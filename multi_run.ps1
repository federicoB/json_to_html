$invocation = (Get-Variable MyInvocation).Value
$pwd = Split-Path $invocation.MyCommand.Path
echo "PS---> Working in: $pwd"

$converter = ".\kml2json.exe"

$FILES_INPUT = Get-ChildItem $pwd -Filter data\*.json
foreach($file_in in $FILES_INPUT)
{
    Write-Host "PS---> Parsing: $file_in"
    $filename = $file_in.ToString().Split('.')
    $file_out = "data\"+$filename[0]+".html"
    &$converter -i data\$file_in -o $file_out
}