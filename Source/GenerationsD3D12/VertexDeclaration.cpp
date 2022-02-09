﻿#include "VertexDeclaration.h"
#include "ConversionHelper.h"

VertexDeclaration::VertexDeclaration(const D3DVERTEXELEMENT9* vertexElements) : count(0)
{
    for (; vertexElements[count].Stream != 0xFF; count++)
        ;

    elementDescriptions = std::make_unique<D3D12_INPUT_ELEMENT_DESC[]>(count);

    for (size_t i = 0; i < count; i++)
    {
        D3D12_INPUT_ELEMENT_DESC& elementDesc = elementDescriptions[i];
        elementDesc.SemanticName = ConversionHelper::getDeclUsageName((D3DDECLUSAGE)vertexElements[i].Usage);
        elementDesc.SemanticIndex = vertexElements[i].UsageIndex;
        elementDesc.Format = ConversionHelper::getDeclType((D3DDECLTYPE)vertexElements[i].Type);
        elementDesc.InputSlot = vertexElements[i].Stream;
        elementDesc.AlignedByteOffset = vertexElements[i].Offset;
        elementDesc.InputSlotClass = D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA;
        elementDesc.InstanceDataStepRate = 0;
    }
}

FUNCTION_STUB(HRESULT, VertexDeclaration::GetDevice, Device** ppDevice)

FUNCTION_STUB(HRESULT, VertexDeclaration::GetDeclaration, D3DVERTEXELEMENT9* pElement, UINT* pNumElements)