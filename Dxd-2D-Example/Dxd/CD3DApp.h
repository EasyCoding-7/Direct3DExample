#pragma once
#include <d3d9.h>

struct FIRE
{
	int nCount;
	int nIndex;
	DWORD dwAniTime;
	DWORD dwOldAniTime;
	RECT *pRect;
	D3DXVECTOR3 *pCenter;
};

FIRE g_sFire;
RECT g_rtFireRect[] = { { 24, 23, 106, 88 }, { 161, 21, 243, 94 }, { 293, 18, 375, 99 },
				{ 21, 109, 103, 196 }, { 161, 119, 243, 183 }, { 293, 109, 375, 188 } };
D3DXVECTOR3 g_vCenter[] = { D3DXVECTOR3(39, 65, 0), D3DXVECTOR3(39, 73, 0),
							D3DXVECTOR3(39, 81, 0), D3DXVECTOR3(39, 87, 0),
							D3DXVECTOR3(39, 64, 0), D3DXVECTOR3(39, 79, 0)
};

class CD3DApp
{
protected:
	LPDIRECT3D9			m_pD3D;
	LPDIRECT3DDEVICE9	m_pd3dDevice;
	HWND				m_hWnd;

	ID3DXSprite *g_Sprite;
	IDirect3DTexture9 *g_pTexture;

	virtual void OnInit() = 0;
	virtual void OnRender() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnRelease() = 0;

public:
	HRESULT InitD3D(HWND hWnd);
	void Render();
	void Update();
	void Cleanup();

public:
	CD3DApp(void);
	~CD3DApp(void);
};

