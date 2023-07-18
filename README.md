# GH D3D9 Test Environment

This repository contains a simple Direct3D 9 test environment that can be used as a playground for experimenting with Direct3D 9 features, testing hacks, and learning about the inner workings of Direct3D 9.

[More info @ GuidedHacking](https://guidedhacking.com/threads/d3d9-11-test-environments.11934/)

Features
--------

The D3D9 Test Environment provides a basic setup for a Direct3D 9 application, including:

-   A native window setup using the Win32 API.
-   Initialization of a Direct3D 9 device.
-   A simple render loop that clears the screen and presents the back buffer.

Code Overview
-------------

The codebase is divided into two main parts: `WinMain.cpp` and `NativeWindow.cpp`.

### WinMain.cpp

This is the entry point of the application. It sets up a native window, initializes Direct3D 9, and enters the main application loop. The loop handles window messages and calls the `Render` function each frame.

The `InitD3D` function is responsible for initializing Direct3D 9. It creates a Direct3D 9 device and a font for drawing text. It also creates a sprite, which can be used for drawing 2D images.

The `Render` function is called each frame. It begins a new scene, clears the screen, draws some text using the previously created font and sprite, ends the scene, and presents the back buffer.

### NativeWindow.cpp

This file contains the `NativeWindow` class, which encapsulates the creation and handling of a native window using the Win32 API. The `Create` function registers a window class and creates a window. The `Register` function registers a window class with the necessary attributes. The `WndProc` function is the window procedure that handles window messages.

FAQ
---

### What is Direct3D 9?

Direct3D 9 is a version of Microsoft's Direct3D API, which is used for rendering 3D graphics in applications. It's part of the DirectX suite of multimedia APIs.

### What is a native window?

A native window is a window that is created using the operating system's native windowing system. In this case, the native windowing system is the Win32 API, which is used to create windows on Windows.

### What is a Direct3D 9 device?

A Direct3D 9 device is an object that represents a display adapter. It's used to create resources (like textures and vertex buffers) and render graphics.

### What is a render loop?

A render loop is the main loop of a graphics application. It's responsible for rendering graphics each frame.

Prerequisites
-------------

To use this code, you should have a good understanding of C++ and the Win32 API. You should also be familiar with the basics of Direct3D 9.

End Goal
--------

The end goal of this source code is to provide a simple Direct3D 9 test environment that can be used as a starting point for experimenting with Direct3D 9, testing hacks, and learning about the inner workings of Direct3D 9.

The D3D9 project makes use of the DXSDK_DIR macro, so if you don't have that set up you may run into errors.  One quick little work around is to just add a new entry to your PATH variable with the name DXSDK_DIR and the value being the path (including trailing '\') to the sdk on disk.

Getting Started
---------------

To get started with the D3D9 Test Environment, you'll need to clone the repository and open the solution file (`TestEnvironmentD3D9.sln`) in Visual Studio. From there, you can build and run the project.

Code Highlights
---------------

Here are a few key pieces of code that you might find interesting:

-   `WinMain.cpp`:

    -   `InitD3D`: This function initializes Direct3D 9. It creates a Direct3D 9 device and a font for drawing text. It also creates a sprite, which can be used for drawing 2D images.
    -   `Render`: This function is called each frame. It begins a new scene, clears the screen, draws some text using the previously created font and sprite, ends the scene, and presents the back buffer.
-   `NativeWindow.cpp`:

    -   `Create`: This function registers a window class and creates a window.
    -   `Register`: This function registers a window class with the necessary attributes.
    -   `WndProc`: This function is the window procedure that handles window messages.

The D3D9 Test Environment is a great starting point for anyone interested in learning about Direct3D 9 or experimenting with game hacks. It provides a simple setup for a Direct3D 9 application, allowing you to focus on the fun stuff.

Related Direct3D Resources​
---------------------------

-   [How to Make an ESP Hack For Any Game](https://guidedhacking.com/threads/how-to-make-an-esp-hack-for-any-game.8313/)
-   [Release - Direct3d9 Stride Logger](https://guidedhacking.com/threads/direct3d9-stride-logger.10095/)
-   [DirectX11 Hook and Logger](https://guidedhacking.com/threads/directx11-hook-and-logger.11910/)
-   [Source Code - DX9 - Image Class](https://guidedhacking.com/threads/dx9-image-class.7620/)
-   [CSGO Direct3D9 EndScene Hook](https://guidedhacking.com/threads/csgo-direct3d9-endscene-hook-d3d9-esp-tutorial-series.14570/)
-   [Tutorial - Direct3D9 Hooking](https://guidedhacking.com/threads/directx9-hooking-need-for-speed-most-wanted-part-1.13389/)
-   [Hooking DirectX11 - Niemand - Cyber Security](https://niemand.com.ar/2019/01/17/improving-your-cheat-template-hooking-directx11/)
-   [How to Hook DirectX 11 - Niemand - Cyber Security](https://niemand.com.ar/2019/01/01/how-to-hook-directx-11-imgui/)
-   [DirectX11 - How to Hook Direct3D11 & Draw Template](https://guidedhacking.com/threads/directx11-how-to-hook-direct3d11-draw-template.15252/)
