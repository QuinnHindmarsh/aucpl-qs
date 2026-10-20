param(
    [Parameter(Mandatory=$true)][string]$SourceFile
)

$isSol = $SourceFile -eq 'sol.cpp'
$exeName = if ($isSol) { 'sol.exe' } else { [System.IO.Path]::GetFileNameWithoutExtension($SourceFile) + '.exe' }
$optFlag = if ($isSol) { '-O2' } else { '-g' }

Write-Host "=== Compiling $SourceFile ===" -ForegroundColor Cyan

if (-not (Get-Command x86_64-w64-mingw32-clang++ -ErrorAction SilentlyContinue)) {
    Write-Host "`n=== COMPILER NOT FOUND: x86_64-w64-mingw32-clang++ is not on PATH ===" -ForegroundColor Red
    exit 1
}

x86_64-w64-mingw32-clang++ -std=c++20 $optFlag -Wall -Wextra -IC:\Users\theto\tools\cpp_shim "-fsanitize=address,undefined" -o $exeName $SourceFile

if ($LASTEXITCODE -ne 0) {
    Write-Host "`n=== COMPILE FAILED (exit code $LASTEXITCODE) ===" -ForegroundColor Red
    exit $LASTEXITCODE
}
Write-Host "=== Compile OK ===" -ForegroundColor Green

if ($isSol -and (Test-Path 'in.txt')) {
    Write-Host "=== Running $exeName < in.txt ===" -ForegroundColor Cyan
    cmd /c ".\$exeName < in.txt"
} else {
    Write-Host "=== Running $exeName ===" -ForegroundColor Cyan
    & ".\$exeName"
}

$rc = $LASTEXITCODE
if ($rc -ne 0) {
    Write-Host "`n=== PROGRAM EXITED WITH CODE $rc ===" -ForegroundColor Red
} else {
    Write-Host "`n=== DONE (exit 0) ===" -ForegroundColor Green
}
exit $rc
