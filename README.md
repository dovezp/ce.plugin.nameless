
# Nameless - The Cheat Engine Renamer Plugin

Welcome to the Nameless Cheat Engine Renamer Plugin repository! If you're a gaming enthusiast or a software developer working in the realm of cheats and hacks, you're about to discover a powerful tool that helps you stay ahead of nonintrusive anti-cheat mechanisms with ease.

### Key Features
* Subvert Detection: This plugin empowers you to bypass nonintrusive anti-cheat window title detection methods, giving you a stealthy advantage.

* Simple and Effective: Designed with simplicity in mind, the Nameless Plugin seamlessly integrates into Cheat Engine, allowing you to focus on what matters most: outsmarting anti-cheats.

* Stay Ahead: By outmaneuvering nonintrusive anti-cheat systems, you can continue to explore game mechanics and uncover hidden features without detection.

### Building Environment

* Visual Studio 2015 with Windows SDK 7.0, 7.1, & 8.1 for System Support of Windows XP - 10
* Visual Studio 2017-2022 with Windows SDK 10 & 11 for System Support of Windows 10 - 11

### Installation
#### Plugin Reminder
* The x86 `nameless` build is compatible with `cheatengine-i386.exe`
* The x64 `nameless` build is compatible with `cheatengine-x86_64.exe` and `cheatengine-x86_64-SSE4-AVX2.exe`
* Both x86 and x64 `nameless` builds reference the same `nameless.ini` file

#### Plugin Setup
1. Extract the most recent [release](https://github.com/dovezp/ce.plugin.nameless/releases) build into the root directory for `Cheat Engine`
    * The root directory where `cheatengine-i386.exe` / `cheatengine-x86_64.exe` is located
2. If needed, configure the `nameless.ini` settings file
3. Start Cheat Engine
4. Go to Edit -> Settings -> Plugins -> Add new
5. Add the nameless dll associated with the Cheat Engine executable (x64 or x86)
6. Click the checkbox next to the nameless dll plugin name to enable 
7. Click Okay to continue
8. You should notice that the plugin is running so start hacking!

### Configuration File Settings

The configuration file contains various settings that control the behavior of the application.

* `random_generation` (Boolean Value)
  * Set this to `True` if you want the application to generate a random string. If set to `False`, the application will rely on the `window_name` setting.
* `refresh_rate_ms` (Integer Value)
  * This setting determines the time interval, in milliseconds, until the next refresh of the window's title.
* `window_name` (String Value)
  * You can specify a custom name for the application's window title here.
  * Leaving this field blank will result in the generation of a random string for the window title.

#### Default Configuration File Settings

Here is an example of the default configuration in `nameless.ini`:

```
[settings]
random_generation = true
refresh_rate_ms = 500
window_name =
```
Feel free to modify these settings in the configuration file according to your requirements.


### License

This project operates under the [BSD 3-Clause License (Revised)](https://tldrlegal.com/license/bsd-3-clause-license-(revised)) ensuring a flexible and open environment for contributors and users.

### Feedback

Your insights, whether positive or critical, are highly valued. Continuous improvement is my goal, and your feedback plays a pivotal role in shaping the future of the Nameless Plugin.

Feel free to share your thoughts and observations by opening a new issue in the repository's issue section. By addressing potential errors, inconsistencies, and suggestions, we can collectively work towards a stronger and more effective tool.

Thank you for contributing to the evolution of the Nameless Cheat Engine Renamer Plugin.

<p align="center">
  <p align="center">
    <a href="https://hits.seeyoufarm.com/api/count/graph/dailyhits.svg?url=https://github.com/dovezp/ce.plugin.nameless">
      <img src="https://hits.seeyoufarm.com/api/count/incr/badge.svg?url=https%3A%2F%2Fgithub.com%2Fdovezp%2Fce.plugin.nameless&count_bg=%2379C83D&title_bg=%23555555&icon=&icon_color=%23E7E7E7&title=hits&edge_flat=true" alt="repository hits">
    </a>
    <a href="https://github.com/dovezp/ce.plugin.nameless/releases">
      <img src="https://img.shields.io/github/downloads/dovezp/ce.plugin.nameless/total?style=flat-square" alt="downloads"/>
    </a>
    <a href="https://github.com/dovezp/ce.plugin.nameless/graphs/contributors">
      <img src="https://img.shields.io/github/contributors/dovezp/ce.plugin.nameless?style=flat-square" alt="contributors"/>
    </a>
    <a href="https://github.com/dovezp/ce.plugin.nameless/watchers">
      <img src="https://img.shields.io/github/watchers/dovezp/ce.plugin.nameless?style=flat-square" alt="watchers"/>
    </a>
    <a href="https://github.com/dovezp/ce.plugin.nameless/stargazers">
      <img src="https://img.shields.io/github/stars/dovezp/ce.plugin.nameless?style=flat-square" alt="stars"/>
    </a>
    <a href="https://github.com/dovezp/ce.plugin.nameless/network/members">
      <img src="https://img.shields.io/github/forks/dovezp/ce.plugin.nameless?style=flat-square" alt="forks"/>
    </a>
  </p>
</p>

<p align="center">
  <a href="https://github.com/dovezp">
    <img width="64" heigth="64" src="https://avatars.githubusercontent.com/u/89095890" alt="dovezp"/>
  </a>
</p>
