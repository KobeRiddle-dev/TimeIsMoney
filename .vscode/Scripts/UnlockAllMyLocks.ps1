$locks = git lfs locks --json | ConvertFrom-Json;

Write-Output("" + $locks.Count + " Locks found for all users");

$user = git config user.name;

$myLocks = $locks | Where-Object {$_.owner.name -eq $user};

Write-Output("" + $myLocks.Count + " Locks found for " + $user);
for ($i = 0; $i -lt $myLocks.Count; $i++)
{
    $lock = $myLocks[$i];
    Write-Output("Unlocking lock on file " + $lock.path + " (" + ($i + 1) + "/" + $myLocks.Count + ")");
    git lfs unlock --id $lock.id;
}