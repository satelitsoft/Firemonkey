//---------------------------------------------------------------------------

#include <fmx.h>
#include <System.Math.hpp>
#pragma hdrstop

#include "LowLevel3DFrm.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

TForm3D2 *Form3D2;

//---------------------------------------------------------------------------
__fastcall TForm3D2::TForm3D2(TComponent* Owner)
	: TForm3D(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMyMaterial::DoApply(Fmx::Types3d::TContext3D* const Context)
{
	TCustomMaterial::DoApply(Context);
	Context->SetShaderVariable("texture0", GetBitmapTexture(Form3D2->InputBitmap->Bitmap));
	Context->SetShaderVariable("texture1", GetBitmapTexture(Form3D2->SecondBitmap->Bitmap));
	TVector3D aMyColorvector[1];
	aMyColorvector[0] = TVector3D::Create(Random(), Random(), Random(), 1);
	Context->SetShaderVariable("MyColor", EXISTINGARRAY(aMyColorvector));
}

//---------------------------------------------------------------------------
System::UnicodeString __fastcall TMyMaterial::DoGetMaterialProperty
	(const Fmx::Types3d::TMaterial::TProperty Prop)
{
	UnicodeString strMaterial;
	switch (Prop) {
		case Fmx::Types3d::TMaterial::TProperty::ModelViewProjection :
			strMaterial = "MVPMatrix";
			break;
	}
	return strMaterial;
}

//---------------------------------------------------------------------------
void __fastcall TMyMaterial::DoInitialize(void)
{
	static const System::Byte ACodeDX9[] = {
		0x00, 0x02, 0xFE, 0xFF, 0xFE, 0xFF, 0x1F, 0x00, 0x43, 0x54, 0x41, 0x42, 0x1C, 0x00, 0x00, 0x00, 0x53, 0x00, 0x00, 0x00, 0x00, 0x02, 0xFE, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x20, 0x4C, 0x00, 0x00, 0x00,
		0x30, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4D, 0x56, 0x50, 0x4D, 0x61, 0x74, 0x72, 0x69, 0x78, 0x00, 0xAB, 0xAB, 0x03, 0x00, 0x03, 0x00, 0x04, 0x00, 0x04, 0x00,
		0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x76, 0x73, 0x5F, 0x32, 0x5F, 0x30, 0x00, 0x4D, 0x69, 0x63, 0x72, 0x6F, 0x73, 0x6F, 0x66, 0x74, 0x20, 0x28, 0x52, 0x29, 0x20, 0x44, 0x33, 0x44, 0x58, 0x39, 0x20, 0x53, 0x68, 0x61, 0x64, 0x65,
		0x72, 0x20, 0x43, 0x6F, 0x6D, 0x70, 0x69, 0x6C, 0x65, 0x72, 0x20, 0x00, 0x1F, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x0F, 0x90, 0x1F, 0x00, 0x00, 0x02, 0x05, 0x00, 0x00, 0x80, 0x01, 0x00, 0x0F, 0x90, 0x05, 0x00, 0x00, 0x03,
		0x00, 0x00, 0x0F, 0x80, 0x00, 0x00, 0x55, 0x90, 0x01, 0x00, 0xE4, 0xA0, 0x04, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x80, 0x00, 0x00, 0xE4, 0xA0, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00, 0xE4, 0x80, 0x04, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x80,
		0x02, 0x00, 0xE4, 0xA0, 0x00, 0x00, 0xAA, 0x90, 0x00, 0x00, 0xE4, 0x80, 0x02, 0x00, 0x00, 0x03, 0x00, 0x00, 0x0F, 0xC0, 0x00, 0x00, 0xE4, 0x80, 0x03, 0x00, 0xE4, 0xA0, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x03, 0xE0, 0x01, 0x00, 0xE4, 0x90,
		0xFF, 0xFF, 0x00, 0x00
	};
	static const System::Byte ACodeDX10[] = {
		0x44, 0x58, 0x42, 0x43, 0xF6, 0x28, 0x77, 0x77, 0xFE, 0x25, 0x25, 0x7B, 0x89, 0xF2, 0xCC, 0xB0, 0x54, 0x09, 0xA0, 0x15, 0x01, 0x00, 0x00, 0x00, 0x30, 0x03, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00, 0x04, 0x01, 0x00, 0x00,
		0x58, 0x01, 0x00, 0x00, 0xB0, 0x01, 0x00, 0x00, 0xB4, 0x02, 0x00, 0x00, 0x52, 0x44, 0x45, 0x46, 0xC8, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x48, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x04, 0xFE, 0xFF,
		0x00, 0x11, 0x00, 0x00, 0x94, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x24, 0x47, 0x6C, 0x6F, 0x62, 0x61, 0x6C, 0x73, 0x00, 0xAB, 0xAB, 0xAB, 0x3C, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4D, 0x56, 0x50, 0x4D, 0x61, 0x74, 0x72, 0x69, 0x78, 0x00, 0xAB, 0xAB, 0x03, 0x00, 0x03, 0x00, 0x04, 0x00, 0x04, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4D, 0x69, 0x63, 0x72, 0x6F, 0x73, 0x6F, 0x66, 0x74, 0x20, 0x28, 0x52, 0x29, 0x20, 0x48, 0x4C, 0x53, 0x4C, 0x20, 0x53, 0x68, 0x61, 0x64, 0x65, 0x72, 0x20, 0x43, 0x6F, 0x6D, 0x70, 0x69, 0x6C,
		0x65, 0x72, 0x20, 0x39, 0x2E, 0x32, 0x36, 0x2E, 0x39, 0x35, 0x32, 0x2E, 0x32, 0x38, 0x34, 0x34, 0x00, 0xAB, 0xAB, 0xAB, 0x49, 0x53, 0x47, 0x4E, 0x4C, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
		0x03, 0x03, 0x00, 0x00, 0x50, 0x4F, 0x53, 0x49, 0x54, 0x49, 0x4F, 0x4E, 0x00, 0x54, 0x45, 0x58, 0x43, 0x4F, 0x4F, 0x52, 0x44, 0x00, 0xAB, 0xAB, 0x4F, 0x53, 0x47, 0x4E, 0x50, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
		0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
		0x01, 0x00, 0x00, 0x00, 0x03, 0x0C, 0x00, 0x00, 0x53, 0x56, 0x5F, 0x50, 0x6F, 0x73, 0x69, 0x74, 0x69, 0x6F, 0x6E, 0x00, 0x54, 0x45, 0x58, 0x43, 0x4F, 0x4F, 0x52, 0x44, 0x00, 0xAB, 0xAB, 0xAB, 0x53, 0x48, 0x44, 0x52, 0xFC, 0x00, 0x00, 0x00,
		0x40, 0x00, 0x01, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x59, 0x00, 0x00, 0x04, 0x46, 0x8E, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x5F, 0x00, 0x00, 0x03, 0x72, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5F, 0x00, 0x00, 0x03,
		0x32, 0x10, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x67, 0x00, 0x00, 0x04, 0xF2, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x65, 0x00, 0x00, 0x03, 0x32, 0x20, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x68, 0x00, 0x00, 0x02,
		0x01, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x08, 0xF2, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x56, 0x15, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x8E, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x0A,
		0xF2, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x8E, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x0E, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x0A,
		0xF2, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x8E, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0xA6, 0x1A, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x0E, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08,
		0xF2, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x0E, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x8E, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x05, 0x32, 0x20, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00,
		0x46, 0x10, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x01, 0x53, 0x54, 0x41, 0x54, 0x74, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	};
	static const System::Byte ACodeGLSL[] = {
		0x61, 0x74, 0x74, 0x72, 0x69, 0x62, 0x75, 0x74, 0x65, 0x20, 0x76, 0x65, 0x63, 0x32, 0x20, 0x61, 0x5F, 0x54, 0x65, 0x78, 0x43, 0x6F, 0x6F, 0x72, 0x64, 0x30, 0x3B, 0x0D, 0x0A, 0x61, 0x74, 0x74, 0x72, 0x69, 0x62, 0x75, 0x74, 0x65, 0x20, 0x76,
		0x65, 0x63, 0x33, 0x20, 0x61, 0x5F, 0x50, 0x6F, 0x73, 0x69, 0x74, 0x69, 0x6F, 0x6E, 0x3B, 0x0D, 0x0A, 0x76, 0x61, 0x72, 0x79, 0x69, 0x6E, 0x67, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x54, 0x45, 0x58, 0x30, 0x3B, 0x0D, 0x0A, 0x76, 0x65, 0x63,
		0x34, 0x20, 0x5F, 0x6F, 0x5F, 0x70, 0x6F, 0x73, 0x31, 0x3B, 0x0D, 0x0A, 0x76, 0x65, 0x63, 0x32, 0x20, 0x5F, 0x6F, 0x5F, 0x74, 0x65, 0x78, 0x63, 0x6F, 0x6F, 0x72, 0x64, 0x30, 0x31, 0x3B, 0x0D, 0x0A, 0x76, 0x65, 0x63, 0x34, 0x20, 0x5F, 0x72,
		0x30, 0x30, 0x30, 0x33, 0x3B, 0x0D, 0x0A, 0x76, 0x65, 0x63, 0x34, 0x20, 0x5F, 0x76, 0x30, 0x30, 0x30, 0x33, 0x3B, 0x0D, 0x0A, 0x75, 0x6E, 0x69, 0x66, 0x6F, 0x72, 0x6D, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x5F, 0x4D, 0x56, 0x50, 0x4D, 0x61,
		0x74, 0x72, 0x69, 0x78, 0x5B, 0x34, 0x5D, 0x3B, 0x0D, 0x0A, 0x76, 0x6F, 0x69, 0x64, 0x20, 0x6D, 0x61, 0x69, 0x6E, 0x28, 0x29, 0x0D, 0x0A, 0x7B, 0x0D, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x5F, 0x76, 0x30, 0x30, 0x30, 0x33, 0x20, 0x3D, 0x20, 0x76,
		0x65, 0x63, 0x34, 0x28, 0x61, 0x5F, 0x50, 0x6F, 0x73, 0x69, 0x74, 0x69, 0x6F, 0x6E, 0x2E, 0x78, 0x2C, 0x20, 0x61, 0x5F, 0x50, 0x6F, 0x73, 0x69, 0x74, 0x69, 0x6F, 0x6E, 0x2E, 0x79, 0x2C, 0x20, 0x61, 0x5F, 0x50, 0x6F, 0x73, 0x69, 0x74, 0x69,
		0x6F, 0x6E, 0x2E, 0x7A, 0x2C, 0x20, 0x31, 0x2E, 0x30, 0x29, 0x3B, 0x0D, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x5F, 0x72, 0x30, 0x30, 0x30, 0x33, 0x2E, 0x78, 0x20, 0x3D, 0x20, 0x64, 0x6F, 0x74, 0x28, 0x5F, 0x4D, 0x56, 0x50, 0x4D, 0x61, 0x74, 0x72,
		0x69, 0x78, 0x5B, 0x30, 0x5D, 0x2C, 0x20, 0x5F, 0x76, 0x30, 0x30, 0x30, 0x33, 0x29, 0x3B, 0x0D, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x5F, 0x72, 0x30, 0x30, 0x30, 0x33, 0x2E, 0x79, 0x20, 0x3D, 0x20, 0x64, 0x6F, 0x74, 0x28, 0x5F, 0x4D, 0x56, 0x50,
		0x4D, 0x61, 0x74, 0x72, 0x69, 0x78, 0x5B, 0x31, 0x5D, 0x2C, 0x20, 0x5F, 0x76, 0x30, 0x30, 0x30, 0x33, 0x29, 0x3B, 0x0D, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x5F, 0x72, 0x30, 0x30, 0x30, 0x33, 0x2E, 0x7A, 0x20, 0x3D, 0x20, 0x64, 0x6F, 0x74, 0x28,
		0x5F, 0x4D, 0x56, 0x50, 0x4D, 0x61, 0x74, 0x72, 0x69, 0x78, 0x5B, 0x32, 0x5D, 0x2C, 0x20, 0x5F, 0x76, 0x30, 0x30, 0x30, 0x33, 0x29, 0x3B, 0x0D, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x5F, 0x72, 0x30, 0x30, 0x30, 0x33, 0x2E, 0x77, 0x20, 0x3D, 0x20,
		0x64, 0x6F, 0x74, 0x28, 0x5F, 0x4D, 0x56, 0x50, 0x4D, 0x61, 0x74, 0x72, 0x69, 0x78, 0x5B, 0x33, 0x5D, 0x2C, 0x20, 0x5F, 0x76, 0x30, 0x30, 0x30, 0x33, 0x29, 0x3B, 0x0D, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x5F, 0x6F, 0x5F, 0x70, 0x6F, 0x73, 0x31,
		0x20, 0x3D, 0x20, 0x5F, 0x72, 0x30, 0x30, 0x30, 0x33, 0x3B, 0x0D, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x5F, 0x6F, 0x5F, 0x74, 0x65, 0x78, 0x63, 0x6F, 0x6F, 0x72, 0x64, 0x30, 0x31, 0x20, 0x3D, 0x20, 0x61, 0x5F, 0x54, 0x65, 0x78, 0x43, 0x6F, 0x6F,
		0x72, 0x64, 0x30, 0x2E, 0x78, 0x79, 0x3B, 0x0D, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x54, 0x45, 0x58, 0x30, 0x2E, 0x78, 0x79, 0x20, 0x3D, 0x20, 0x61, 0x5F, 0x54, 0x65, 0x78, 0x43, 0x6F, 0x6F, 0x72, 0x64, 0x30, 0x2E, 0x78, 0x79, 0x3B, 0x0D, 0x0A,
		0x20, 0x20, 0x20, 0x20, 0x67, 0x6C, 0x5F, 0x50, 0x6F, 0x73, 0x69, 0x74, 0x69, 0x6F, 0x6E, 0x20, 0x3D, 0x20, 0x5F, 0x72, 0x30, 0x30, 0x30, 0x33, 0x3B, 0x0D, 0x0A, 0x7D, 0x20, 0x0D, 0x0A
	};

	TContextShaderVariable aVertexShaderDX09("MVPMatrix", TContextShaderVariableKind::vkMatrix, 0, 4);
	TContextShaderVariable aaVertexShaderDX09[1];
	aaVertexShaderDX09[0] = aVertexShaderDX09;

	TContextShaderVariable aVertexSharedDX10("MVPMatrix", TContextShaderVariableKind::vkMatrix, 0, 64);
	TContextShaderVariable aaVertexSharedDX10[1];
	aaVertexSharedDX10[0] = aVertexSharedDX10;

	TContextShaderVariable aVertexSharedDXGL("MVPMatrix", TContextShaderVariableKind::vkMatrix, 0, 4);
	TContextShaderVariable aaVertexSharedDXGL[1];
	aaVertexSharedDXGL[0] = aVertexSharedDXGL;

	TContextShaderSource sourcesVertexShaderDX09(TContextShaderArch::saDX9,  EXISTINGARRAY(ACodeDX9), EXISTINGARRAY(aaVertexShaderDX09));
	TContextShaderSource sourcesVertexShaderDX10(TContextShaderArch::saDX10, EXISTINGARRAY(ACodeDX10), EXISTINGARRAY(aaVertexSharedDX10));
	TContextShaderSource sourcesVertexShaderDXGL(TContextShaderArch::saGLSL, EXISTINGARRAY(ACodeGLSL), EXISTINGARRAY(aaVertexSharedDXGL));

	TContextShaderSource sourcesVertexShader[3];
	sourcesVertexShader[0] = sourcesVertexShaderDX09;
	sourcesVertexShader[1] = sourcesVertexShaderDX10;
	sourcesVertexShader[2] = sourcesVertexShaderDXGL;



	FVertexShader = TShaderManager::RegisterShaderFromData("hw.fvs",
		TContextShaderKind::skVertexShader,
		"    float4x4 MVPMatrix; "
		"    void main(float3 a_position : POSITION, "
		"              float2 a_texcoord0: TEXCOORD0, "
		"              out float4 o_pos : POSITION, "
		"              out float2 o_texcoord0 : TEXCOORD0) "
		"    { "
		"      o_pos = mul(MVPMatrix, float4(a_position, 1.0)); "
		"      o_texcoord0 = a_texcoord0; "
		"    }",
		EXISTINGARRAY(sourcesVertexShader));

	static const System::Byte ACodeSaDX9[] = {
		0x00, 0x02, 0xFF, 0xFF, 0xFE, 0xFF, 0x32, 0x00, 0x43, 0x54, 0x41, 0x42, 0x1C, 0x00, 0x00, 0x00, 0x9C, 0x00, 0x00, 0x00, 0x00, 0x02, 0xFF, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x20, 0x95, 0x00, 0x00, 0x00,
		0x58, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x8C, 0x00, 0x00, 0x00, 0x03, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4D, 0x79, 0x43, 0x6F, 0x6C, 0x6F, 0x72, 0x00, 0x01, 0x00, 0x03, 0x00, 0x01, 0x00, 0x04, 0x00, 0x01, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x30, 0x00, 0xAB, 0xAB, 0xAB, 0x04, 0x00, 0x0C, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x31,
		0x00, 0x70, 0x73, 0x5F, 0x32, 0x5F, 0x30, 0x00, 0x4D, 0x69, 0x63, 0x72, 0x6F, 0x73, 0x6F, 0x66, 0x74, 0x20, 0x28, 0x52, 0x29, 0x20, 0x44, 0x33, 0x44, 0x58, 0x39, 0x20, 0x53, 0x68, 0x61, 0x64, 0x65, 0x72, 0x20, 0x43, 0x6F, 0x6D, 0x70, 0x69,
		0x6C, 0x65, 0x72, 0x20, 0x00, 0xAB, 0xAB, 0xAB, 0x51, 0x00, 0x00, 0x05, 0x01, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x80, 0xBE, 0x00, 0x00, 0x00, 0xBF, 0x00, 0x00, 0x40, 0xBF, 0x00, 0x00, 0x00, 0x00, 0x51, 0x00, 0x00, 0x05, 0x02, 0x00, 0x0F, 0xA0,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x03, 0xB0, 0x1F, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x90, 0x00, 0x08, 0x0F, 0xA0,
		0x1F, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x90, 0x01, 0x08, 0x0F, 0xA0, 0x42, 0x00, 0x00, 0x03, 0x00, 0x00, 0x0F, 0x80, 0x00, 0x00, 0xE4, 0xB0, 0x00, 0x08, 0xE4, 0xA0, 0x42, 0x00, 0x00, 0x03, 0x01, 0x00, 0x0F, 0x80, 0x00, 0x00, 0xE4, 0xB0,
		0x01, 0x08, 0xE4, 0xA0, 0x02, 0x00, 0x00, 0x03, 0x02, 0x00, 0x08, 0x80, 0x00, 0x00, 0x00, 0xB0, 0x01, 0x00, 0xAA, 0xA0, 0x01, 0x00, 0x00, 0x02, 0x03, 0x00, 0x03, 0x80, 0x00, 0x00, 0xE4, 0xB0, 0x01, 0x00, 0x00, 0x02, 0x03, 0x00, 0x04, 0x80,
		0x02, 0x00, 0x00, 0xA0, 0x01, 0x00, 0x00, 0x02, 0x03, 0x00, 0x08, 0x80, 0x02, 0x00, 0x55, 0xA0, 0x58, 0x00, 0x00, 0x04, 0x02, 0x00, 0x0F, 0x80, 0x02, 0x00, 0xFF, 0x80, 0x00, 0x00, 0xE4, 0xA0, 0x03, 0x00, 0xE4, 0x80, 0x02, 0x00, 0x00, 0x03,
		0x03, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0xB0, 0x01, 0x00, 0x55, 0xA0, 0x58, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x80, 0x03, 0x00, 0x00, 0x80, 0x02, 0x00, 0xE4, 0x80, 0x00, 0x00, 0xE4, 0x80, 0x02, 0x00, 0x00, 0x03, 0x02, 0x00, 0x01, 0x80,
		0x00, 0x00, 0x00, 0xB0, 0x01, 0x00, 0x00, 0xA0, 0x58, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x80, 0x02, 0x00, 0x00, 0x80, 0x00, 0x00, 0xE4, 0x80, 0x01, 0x00, 0xE4, 0x80, 0x01, 0x00, 0x00, 0x02, 0x00, 0x08, 0x0F, 0x80, 0x00, 0x00, 0xE4, 0x80,
		0xFF, 0xFF, 0x00, 0x00
	};
	static const System::Byte ACodeSaDX10[] = {
		0x44, 0x58, 0x42, 0x43, 0x39, 0x0D, 0x73, 0x2B, 0x78, 0x34, 0x48, 0xB8, 0x20, 0x97, 0xD3, 0x58, 0xBB, 0x29, 0xD3, 0xA6, 0x01, 0x00, 0x00, 0x00, 0x38, 0x04, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00, 0x90, 0x01, 0x00, 0x00,
		0xE8, 0x01, 0x00, 0x00, 0x1C, 0x02, 0x00, 0x00, 0xBC, 0x03, 0x00, 0x00, 0x52, 0x44, 0x45, 0x46, 0x54, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0xD8, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x04, 0xFF, 0xFF,
		0x00, 0x11, 0x00, 0x00, 0x20, 0x01, 0x00, 0x00, 0xBC, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xC5, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC5, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
		0x05, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0xBC, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0xCE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x30, 0x00, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x31, 0x00, 0x24, 0x47, 0x6C, 0x6F, 0x62, 0x61, 0x6C, 0x73, 0x00, 0xAB, 0xCE, 0x00, 0x00, 0x00,
		0x01, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x10, 0x01, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x4D, 0x79, 0x43, 0x6F, 0x6C, 0x6F, 0x72, 0x00, 0x01, 0x00, 0x03, 0x00, 0x01, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4D, 0x69, 0x63, 0x72, 0x6F, 0x73, 0x6F, 0x66, 0x74, 0x20, 0x28, 0x52,
		0x29, 0x20, 0x48, 0x4C, 0x53, 0x4C, 0x20, 0x53, 0x68, 0x61, 0x64, 0x65, 0x72, 0x20, 0x43, 0x6F, 0x6D, 0x70, 0x69, 0x6C, 0x65, 0x72, 0x20, 0x39, 0x2E, 0x32, 0x36, 0x2E, 0x39, 0x35, 0x32, 0x2E, 0x32, 0x38, 0x34, 0x34, 0x00, 0xAB, 0xAB, 0xAB,
		0x49, 0x53, 0x47, 0x4E, 0x50, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00,
		0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x53, 0x56, 0x5F, 0x50, 0x6F, 0x73, 0x69, 0x74, 0x69, 0x6F, 0x6E, 0x00, 0x54, 0x45, 0x58, 0x43,
		0x4F, 0x4F, 0x52, 0x44, 0x00, 0xAB, 0xAB, 0xAB, 0x4F, 0x53, 0x47, 0x4E, 0x2C, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x53, 0x56, 0x5F, 0x54, 0x61, 0x72, 0x67, 0x65, 0x74, 0x00, 0xAB, 0xAB, 0x53, 0x48, 0x44, 0x52, 0x98, 0x01, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x66, 0x00, 0x00, 0x00, 0x59, 0x00, 0x00, 0x04,
		0x46, 0x8E, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x5A, 0x00, 0x00, 0x03, 0x00, 0x60, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5A, 0x00, 0x00, 0x03, 0x00, 0x60, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x58, 0x18, 0x00, 0x04,
		0x00, 0x70, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x55, 0x00, 0x00, 0x58, 0x18, 0x00, 0x04, 0x00, 0x70, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x55, 0x55, 0x00, 0x00, 0x62, 0x10, 0x00, 0x03, 0x32, 0x10, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00,
		0x65, 0x00, 0x00, 0x03, 0xF2, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x68, 0x00, 0x00, 0x02, 0x01, 0x00, 0x00, 0x00, 0x31, 0x00, 0x00, 0x07, 0x12, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x10, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00,
		0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3E, 0x1F, 0x00, 0x04, 0x03, 0x0A, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x45, 0x00, 0x00, 0x09, 0xF2, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x10, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00,
		0x46, 0x7E, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x01, 0x15, 0x00, 0x00, 0x01, 0x31, 0x00, 0x00, 0x07, 0x12, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x10, 0x10, 0x00,
		0x01, 0x00, 0x00, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x1F, 0x00, 0x04, 0x03, 0x0A, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x45, 0x00, 0x00, 0x09, 0xF2, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x10, 0x10, 0x00,
		0x01, 0x00, 0x00, 0x00, 0x46, 0x7E, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x60, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x01, 0x15, 0x00, 0x00, 0x01, 0x31, 0x00, 0x00, 0x07, 0x12, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x0A, 0x10, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x40, 0x3F, 0x1F, 0x00, 0x04, 0x03, 0x0A, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x05, 0x32, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x46, 0x10, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x08, 0xC2, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3F,
		0x3E, 0x00, 0x00, 0x01, 0x15, 0x00, 0x00, 0x01, 0x36, 0x00, 0x00, 0x06, 0xF2, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x8E, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x01, 0x53, 0x54, 0x41, 0x54,
		0x74, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	};
	static const System::Byte ACodeSaGLSL[] = {
		0x76, 0x61, 0x72, 0x79, 0x69, 0x6E, 0x67, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x54, 0x45, 0x58, 0x30, 0x3B, 0x0A, 0x0D, 0x2F, 0x2F, 0x20, 0x67, 0x6C, 0x73, 0x6C, 0x66, 0x20, 0x6F, 0x75, 0x74, 0x70, 0x75, 0x74, 0x20, 0x62, 0x79, 0x20, 0x43,
		0x67, 0x20, 0x63, 0x6F, 0x6D, 0x70, 0x69, 0x6C, 0x65, 0x72, 0x0A, 0x2F, 0x2F, 0x20, 0x63, 0x67, 0x63, 0x20, 0x76, 0x65, 0x72, 0x73, 0x69, 0x6F, 0x6E, 0x20, 0x33, 0x2E, 0x30, 0x2E, 0x30, 0x30, 0x31, 0x36, 0x2C, 0x20, 0x62, 0x75, 0x69, 0x6C,
		0x64, 0x20, 0x64, 0x61, 0x74, 0x65, 0x20, 0x46, 0x65, 0x62, 0x20, 0x31, 0x31, 0x20, 0x32, 0x30, 0x31, 0x31, 0x0A, 0x2F, 0x2F, 0x20, 0x63, 0x6F, 0x6D, 0x6D, 0x61, 0x6E, 0x64, 0x20, 0x6C, 0x69, 0x6E, 0x65, 0x20, 0x61, 0x72, 0x67, 0x73, 0x3A,
		0x20, 0x2D, 0x71, 0x20, 0x2D, 0x70, 0x72, 0x6F, 0x66, 0x69, 0x6C, 0x65, 0x20, 0x67, 0x6C, 0x73, 0x6C, 0x66, 0x20, 0x2D, 0x65, 0x6E, 0x74, 0x72, 0x79, 0x20, 0x6D, 0x61, 0x69, 0x6E, 0x0A, 0x2F, 0x2F, 0x20, 0x73, 0x6F, 0x75, 0x72, 0x63, 0x65,
		0x20, 0x66, 0x69, 0x6C, 0x65, 0x3A, 0x20, 0x68, 0x77, 0x2E, 0x66, 0x70, 0x73, 0x0A, 0x2F, 0x2F, 0x76, 0x65, 0x6E, 0x64, 0x6F, 0x72, 0x20, 0x4E, 0x56, 0x49, 0x44, 0x49, 0x41, 0x20, 0x43, 0x6F, 0x72, 0x70, 0x6F, 0x72, 0x61, 0x74, 0x69, 0x6F,
		0x6E, 0x0A, 0x2F, 0x2F, 0x76, 0x65, 0x72, 0x73, 0x69, 0x6F, 0x6E, 0x20, 0x33, 0x2E, 0x30, 0x2E, 0x30, 0x2E, 0x31, 0x36, 0x0A, 0x2F, 0x2F, 0x70, 0x72, 0x6F, 0x66, 0x69, 0x6C, 0x65, 0x20, 0x67, 0x6C, 0x73, 0x6C, 0x66, 0x0A, 0x2F, 0x2F, 0x70,
		0x72, 0x6F, 0x67, 0x72, 0x61, 0x6D, 0x20, 0x6D, 0x61, 0x69, 0x6E, 0x0A, 0x2F, 0x2F, 0x73, 0x65, 0x6D, 0x61, 0x6E, 0x74, 0x69, 0x63, 0x20, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x30, 0x0A, 0x2F, 0x2F, 0x73, 0x65, 0x6D, 0x61, 0x6E, 0x74,
		0x69, 0x63, 0x20, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x31, 0x0A, 0x2F, 0x2F, 0x73, 0x65, 0x6D, 0x61, 0x6E, 0x74, 0x69, 0x63, 0x20, 0x4D, 0x79, 0x43, 0x6F, 0x6C, 0x6F, 0x72, 0x0A, 0x2F, 0x2F, 0x76, 0x61, 0x72, 0x20, 0x73, 0x61, 0x6D,
		0x70, 0x6C, 0x65, 0x72, 0x32, 0x44, 0x20, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x30, 0x20, 0x3A, 0x20, 0x20, 0x3A, 0x20, 0x5F, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x30, 0x20, 0x3A, 0x20, 0x2D, 0x31, 0x20, 0x3A, 0x20, 0x31, 0x0A,
		0x2F, 0x2F, 0x76, 0x61, 0x72, 0x20, 0x73, 0x61, 0x6D, 0x70, 0x6C, 0x65, 0x72, 0x32, 0x44, 0x20, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x31, 0x20, 0x3A, 0x20, 0x20, 0x3A, 0x20, 0x5F, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x31, 0x20,
		0x3A, 0x20, 0x2D, 0x31, 0x20, 0x3A, 0x20, 0x31, 0x0A, 0x2F, 0x2F, 0x76, 0x61, 0x72, 0x20, 0x66, 0x6C, 0x6F, 0x61, 0x74, 0x34, 0x20, 0x4D, 0x79, 0x43, 0x6F, 0x6C, 0x6F, 0x72, 0x20, 0x3A, 0x20, 0x20, 0x3A, 0x20, 0x5F, 0x4D, 0x79, 0x43, 0x6F,
		0x6C, 0x6F, 0x72, 0x20, 0x3A, 0x20, 0x2D, 0x31, 0x20, 0x3A, 0x20, 0x31, 0x0A, 0x2F, 0x2F, 0x76, 0x61, 0x72, 0x20, 0x66, 0x6C, 0x6F, 0x61, 0x74, 0x32, 0x20, 0x69, 0x6E, 0x70, 0x75, 0x74, 0x2E, 0x54, 0x65, 0x78, 0x30, 0x20, 0x3A, 0x20, 0x24,
		0x76, 0x69, 0x6E, 0x2E, 0x54, 0x45, 0x58, 0x43, 0x4F, 0x4F, 0x52, 0x44, 0x30, 0x20, 0x3A, 0x20, 0x54, 0x45, 0x58, 0x43, 0x4F, 0x4F, 0x52, 0x44, 0x30, 0x20, 0x3A, 0x20, 0x30, 0x20, 0x3A, 0x20, 0x31, 0x0A, 0x2F, 0x2F, 0x76, 0x61, 0x72, 0x20,
		0x66, 0x6C, 0x6F, 0x61, 0x74, 0x34, 0x20, 0x6D, 0x61, 0x69, 0x6E, 0x20, 0x3A, 0x20, 0x24, 0x76, 0x6F, 0x75, 0x74, 0x2E, 0x43, 0x4F, 0x4C, 0x4F, 0x52, 0x20, 0x3A, 0x20, 0x43, 0x4F, 0x4C, 0x20, 0x3A, 0x20, 0x2D, 0x31, 0x20, 0x3A, 0x20, 0x31,
		0x0A, 0x0A, 0x73, 0x74, 0x72, 0x75, 0x63, 0x74, 0x20, 0x50, 0x53, 0x49, 0x6E, 0x70, 0x75, 0x74, 0x20, 0x7B, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x76, 0x65, 0x63, 0x32, 0x20, 0x5F, 0x54, 0x65, 0x78, 0x30, 0x3B, 0x0A, 0x7D, 0x3B, 0x0A, 0x0A, 0x76,
		0x65, 0x63, 0x34, 0x20, 0x5F, 0x72, 0x65, 0x74, 0x5F, 0x30, 0x3B, 0x0A, 0x75, 0x6E, 0x69, 0x66, 0x6F, 0x72, 0x6D, 0x20, 0x73, 0x61, 0x6D, 0x70, 0x6C, 0x65, 0x72, 0x32, 0x44, 0x20, 0x5F, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x30, 0x3B,
		0x0A, 0x75, 0x6E, 0x69, 0x66, 0x6F, 0x72, 0x6D, 0x20, 0x73, 0x61, 0x6D, 0x70, 0x6C, 0x65, 0x72, 0x32, 0x44, 0x20, 0x5F, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x31, 0x3B, 0x0A, 0x75, 0x6E, 0x69, 0x66, 0x6F, 0x72, 0x6D, 0x20, 0x76, 0x65,
		0x63, 0x34, 0x20, 0x5F, 0x4D, 0x79, 0x43, 0x6F, 0x6C, 0x6F, 0x72, 0x3B, 0x0A, 0x0A, 0x20, 0x2F, 0x2F, 0x20, 0x6D, 0x61, 0x69, 0x6E, 0x20, 0x70, 0x72, 0x6F, 0x63, 0x65, 0x64, 0x75, 0x72, 0x65, 0x2C, 0x20, 0x74, 0x68, 0x65, 0x20, 0x6F, 0x72,
		0x69, 0x67, 0x69, 0x6E, 0x61, 0x6C, 0x20, 0x6E, 0x61, 0x6D, 0x65, 0x20, 0x77, 0x61, 0x73, 0x20, 0x6D, 0x61, 0x69, 0x6E, 0x0A, 0x76, 0x6F, 0x69, 0x64, 0x20, 0x6D, 0x61, 0x69, 0x6E, 0x28, 0x29, 0x0A, 0x7B, 0x0A, 0x0A, 0x0A, 0x20, 0x20, 0x20,
		0x20, 0x69, 0x66, 0x20, 0x28, 0x54, 0x45, 0x58, 0x30, 0x2E, 0x78, 0x20, 0x3C, 0x20, 0x32, 0x2E, 0x35, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x45, 0x2D, 0x30, 0x30, 0x31, 0x29, 0x20, 0x7B, 0x20, 0x2F, 0x2F, 0x20, 0x69, 0x66, 0x20, 0x62,
		0x65, 0x67, 0x69, 0x6E, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5F, 0x72, 0x65, 0x74, 0x5F, 0x30, 0x20, 0x3D, 0x20, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x32, 0x44, 0x28, 0x5F, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65,
		0x31, 0x2C, 0x20, 0x54, 0x45, 0x58, 0x30, 0x2E, 0x78, 0x79, 0x29, 0x3B, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x67, 0x6C, 0x5F, 0x46, 0x72, 0x61, 0x67, 0x43, 0x6F, 0x6C, 0x6F, 0x72, 0x20, 0x3D, 0x20, 0x5F, 0x72, 0x65, 0x74,
		0x5F, 0x30, 0x3B, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x72, 0x65, 0x74, 0x75, 0x72, 0x6E, 0x3B, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x7D, 0x20, 0x2F, 0x2F, 0x20, 0x65, 0x6E, 0x64, 0x20, 0x69, 0x66, 0x0A, 0x20, 0x20, 0x20, 0x20,
		0x69, 0x66, 0x20, 0x28, 0x54, 0x45, 0x58, 0x30, 0x2E, 0x78, 0x20, 0x3C, 0x20, 0x35, 0x2E, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x45, 0x2D, 0x30, 0x30, 0x31, 0x29, 0x20, 0x7B, 0x20, 0x2F, 0x2F, 0x20, 0x69, 0x66, 0x20, 0x62, 0x65,
		0x67, 0x69, 0x6E, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5F, 0x72, 0x65, 0x74, 0x5F, 0x30, 0x20, 0x3D, 0x20, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x32, 0x44, 0x28, 0x5F, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x30,
		0x2C, 0x20, 0x54, 0x45, 0x58, 0x30, 0x2E, 0x78, 0x79, 0x29, 0x3B, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x67, 0x6C, 0x5F, 0x46, 0x72, 0x61, 0x67, 0x43, 0x6F, 0x6C, 0x6F, 0x72, 0x20, 0x3D, 0x20, 0x5F, 0x72, 0x65, 0x74, 0x5F,
		0x30, 0x3B, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x72, 0x65, 0x74, 0x75, 0x72, 0x6E, 0x3B, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x7D, 0x20, 0x2F, 0x2F, 0x20, 0x65, 0x6E, 0x64, 0x20, 0x69, 0x66, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x69,
		0x66, 0x20, 0x28, 0x54, 0x45, 0x58, 0x30, 0x2E, 0x78, 0x20, 0x3C, 0x20, 0x37, 0x2E, 0x35, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x45, 0x2D, 0x30, 0x30, 0x31, 0x29, 0x20, 0x7B, 0x20, 0x2F, 0x2F, 0x20, 0x69, 0x66, 0x20, 0x62, 0x65, 0x67,
		0x69, 0x6E, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5F, 0x72, 0x65, 0x74, 0x5F, 0x30, 0x20, 0x3D, 0x20, 0x76, 0x65, 0x63, 0x34, 0x28, 0x54, 0x45, 0x58, 0x30, 0x2E, 0x78, 0x2C, 0x20, 0x54, 0x45, 0x58, 0x30, 0x2E, 0x79, 0x2C,
		0x20, 0x30, 0x2E, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x45, 0x2B, 0x30, 0x30, 0x30, 0x2C, 0x20, 0x31, 0x2E, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x45, 0x2B, 0x30, 0x30, 0x30, 0x29, 0x3B, 0x0A, 0x20, 0x20, 0x20, 0x20,
		0x20, 0x20, 0x20, 0x20, 0x67, 0x6C, 0x5F, 0x46, 0x72, 0x61, 0x67, 0x43, 0x6F, 0x6C, 0x6F, 0x72, 0x20, 0x3D, 0x20, 0x5F, 0x72, 0x65, 0x74, 0x5F, 0x30, 0x3B, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x72, 0x65, 0x74, 0x75, 0x72,
		0x6E, 0x3B, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x7D, 0x20, 0x2F, 0x2F, 0x20, 0x65, 0x6E, 0x64, 0x20, 0x69, 0x66, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x67, 0x6C, 0x5F, 0x46, 0x72, 0x61, 0x67, 0x43, 0x6F, 0x6C, 0x6F, 0x72, 0x20, 0x3D, 0x20, 0x5F, 0x4D,
		0x79, 0x43, 0x6F, 0x6C, 0x6F, 0x72, 0x3B, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x72, 0x65, 0x74, 0x75, 0x72, 0x6E, 0x3B, 0x0A, 0x7D, 0x20, 0x2F, 0x2F, 0x20, 0x6D, 0x61, 0x69, 0x6E, 0x20, 0x65, 0x6E, 0x64, 0x0A
	};

	TContextShaderVariable MyColorDX9("MyColor",   TContextShaderVariableKind::vkVector,  0, 1);
	TContextShaderVariable texture0DX9("texture0", TContextShaderVariableKind::vkTexture, 0, 0);
	TContextShaderVariable texture1DX9("texture1", TContextShaderVariableKind::vkTexture, 1, 0);

	TContextShaderVariable sharedVarDX9[3];
	sharedVarDX9[0] = MyColorDX9;
	sharedVarDX9[1]	= texture0DX9;
	sharedVarDX9[2] = texture1DX9;

	TContextShaderVariable texture0DX10("texture0", TContextShaderVariableKind::vkTexture, 0, 0);
	TContextShaderVariable texture1DX10("texture1", TContextShaderVariableKind::vkTexture, 1, 0);
	TContextShaderVariable MyColorDX10("MyColor",   TContextShaderVariableKind::vkVector,  0, 16);

	TContextShaderVariable sharedVarDX10[3];
	sharedVarDX10[0] = texture0DX10;
	sharedVarDX10[1] = texture1DX10;
	sharedVarDX10[2] = MyColorDX10;

	TContextShaderVariable texture0GLSL("texture0", TContextShaderVariableKind::vkTexture, 0, 0);
	TContextShaderVariable texture1GLSL("texture1", TContextShaderVariableKind::vkTexture, 1, 0);
	TContextShaderVariable MyColorGLSL("MyColor",   TContextShaderVariableKind::vkVector,  0, 1);

	TContextShaderVariable sharedVarGLSL[3];
	sharedVarGLSL[0] = texture0GLSL;
	sharedVarGLSL[1] = texture1GLSL;
	sharedVarGLSL[2] = MyColorGLSL;

	TContextShaderSource sourcesPixelShaderDX09(TContextShaderArch::saDX9,  EXISTINGARRAY(ACodeSaDX9), EXISTINGARRAY(sharedVarDX9));
	TContextShaderSource sourcesPixelShaderDX10(TContextShaderArch::saDX10, EXISTINGARRAY(ACodeSaDX10), EXISTINGARRAY(sharedVarDX10));
	TContextShaderSource sourcesPixelShaderDXGL(TContextShaderArch::saGLSL, EXISTINGARRAY(ACodeSaGLSL), EXISTINGARRAY(sharedVarGLSL));

	TContextShaderSource sourcesPixelShader[3];
	sourcesPixelShader[0] = sourcesPixelShaderDX09;
	sourcesPixelShader[1] = sourcesPixelShaderDX10;
	sourcesPixelShader[2] = sourcesPixelShaderDXGL;

	FPixelShader = TShaderManager::RegisterShaderFromData("hw.fps",
		TContextShaderKind::skPixelShader,
		"    sampler2D texture0; "
		"    sampler2D texture1; "
		"    float4 MyColor; "
		"    struct PSInput "
		"    { "
		"      float4 Pos  : POSITION; "
		"      float2 Tex0 : TEXCOORD0; "
		"    }; "
		"    float4 main( PSInput input ): COLOR "
		"    { "
		"      if (input.Tex0.x < 0.25) "
		"        return tex2D(texture1, input.Tex0); "
		"      if (input.Tex0.x < 0.5) "
		"        return tex2D(texture0, input.Tex0); "
		"      if (input.Tex0.x < 0.75) "
		"        return float4(input.Tex0, 0, 1.0); "
		"      return MyColor; "
		"    }",
		EXISTINGARRAY(sourcesPixelShader));
}
//---------------------------------------------------------------------------
void __fastcall TForm3D2::Form3DRender(TObject *Sender, TContext3D *Context)
{
	// Set Vertices
	TVertexBuffer * Ver = new TVertexBuffer(TVertexFormats() << TVertexFormat::vfVertex <<
		TVertexFormat::vfTexCoord0, 4);
	Ver->Vertices[0]  = Point3D(-6, 0, -5);
	Ver->TexCoord0[0] = PointF(0, 0);
	Ver->Vertices[1]  = Point3D( 6, 0, -5);
	Ver->TexCoord0[1] = PointF(1, 0);
	Ver->Vertices[2]  = Point3D( 6, 0,  5);
	Ver->TexCoord0[2] = PointF(1, 1);
	Ver->Vertices[3]  = Point3D(-6, 0,  5);
	Ver->TexCoord0[3] = PointF(0, 1);
	// Set Indices
	TIndexBuffer * Idx = new TIndexBuffer(6, TIndexFormat::ifUInt16);
	Idx->Indices[0] = 0;
	Idx->Indices[1] = 1;
	Idx->Indices[2] = 3;
	Idx->Indices[3] = 3;
	Idx->Indices[4] = 1;
	Idx->Indices[5] = 2;
	// Set matrix
	Context->SetMatrix(TMatrix3D::CreateRotation(TPoint3D::Create(1,0,0), DegToRad(TagFloat)));
	// Set states
	Context->SetContextState(TContextState::csAllFace);
	// Create material
	TMyMaterial *Mat = new TMyMaterial();
	// render
	Context->DrawTriangles(Ver, Idx, Mat, 1);
	// dispose
	delete Mat;
	Ver->Free();
	Idx->Free();
}
//---------------------------------------------------------------------------
void __fastcall TForm3D2::Timer1Timer(TObject *Sender)
{
	TagFloat += 1;
	Invalidate();
}
//---------------------------------------------------------------------------

