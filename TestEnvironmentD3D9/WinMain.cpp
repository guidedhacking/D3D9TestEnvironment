#include <stdio.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "NativeWindow.h"

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

IDirect3D9* pD3d = nullptr;
IDirect3DDevice9* pDevice = nullptr;
ID3DXFont* pFont = nullptr;
ID3DXSprite* pSprite = nullptr;
char szDevice[256]{ 0 };

bool InitD3D(HWND hWnd, UINT uWidth, UINT uHeight)
{
	pD3d = Direct3DCreate9( D3D_SDK_VERSION );
	D3DPRESENT_PARAMETERS dp{ 0 };
	dp.BackBufferWidth = uWidth;
	dp.BackBufferHeight = uHeight;
	dp.hDeviceWindow = hWnd;
	dp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	dp.Windowed = TRUE;

	HRESULT hr = pD3d->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &dp, &pDevice );
	if (FAILED( hr ) || !pDevice)
	{
		MessageBox( NULL, _T( "Failed to create D3D Device." ), _T( "Error" ), MB_ICONERROR | MB_OK );
		return false;
	}

	sprintf_s( szDevice, 256, "DevicePtr: 0x%p", &pDevice );

	// Create font to draw string
	hr = D3DXCreateFont( pDevice, 21, 0, FW_NORMAL, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, _T( "Consolas" ), &pFont );
	if (FAILED( hr ))
	{
		MessageBox( NULL, _T( "Failed to create font." ), _T( "Error" ), MB_ICONERROR | MB_OK );
		return false;
	}

	hr = D3DXCreateSprite( pDevice, &pSprite );
	if (FAILED( hr ))
	{
		MessageBox( NULL, _T( "Failed to create sprite." ), _T( "Error" ), MB_ICONERROR | MB_OK );
		return false;
	}

	return true;
}

void Render(NativeWindow& wnd)
{
	pDevice->BeginScene();
	pDevice->Clear( 1, nullptr, D3DCLEAR_TARGET, 0x00111111, 1.0f, 0 );

	RECT rc = { 0, 0, WND_WIDTH, WND_HEIGHT };
	pSprite->Begin( D3DXSPRITE_ALPHABLEND );
	pFont->DrawTextA( pSprite, szDevice, strlen(szDevice), &rc, DT_NOCLIP, 0xFFFFFFFF );
	pSprite->End();

	pDevice->EndScene();
	pDevice->Present( 0, 0, 0, 0 );
}

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	NativeWindow wnd;

	wnd.Create( hInstance, nCmdShow );

	if (!InitD3D( wnd.GetHandle(), WND_WIDTH, WND_HEIGHT ))
		return 1;

	MSG m;
	while (true)
	{
		while (PeekMessage( &m, NULL, 0, 0, PM_REMOVE ) && m.message != WM_QUIT)
		{
			TranslateMessage( &m );
			DispatchMessage( &m );
		}
		if (m.message == WM_QUIT)
			break;

		Render(wnd);
	}

	return 0;
}