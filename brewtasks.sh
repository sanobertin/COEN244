#auto update brew
brew autoupdate status
brew autoupdate

#cleanup brew
brew cleanup

#List all installed formulae.
brew list -v
#Uninstall formulae that were only installed as a dependency of another formula and are now no longer needed.
brew autoremove

#Check your system for potential problems.
brew doctor -v
#Automatically upgrade your installed formulae.
brew autoupdate --upgrade
brew autoupdate --cleanup