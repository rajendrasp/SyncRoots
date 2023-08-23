#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"

#include <winrt/Windows.Storage.Provider.h>

using namespace winrt;
using namespace Windows::UI::Xaml;
using namespace Windows::Storage::Provider;

namespace winrt::SyncRoots::implementation
{
    int32_t MainPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void  MainPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
        if (StorageProviderSyncRootManager::IsSupported())
        {
            auto roots = StorageProviderSyncRootManager::GetCurrentSyncRoots();

            for (auto& root : roots)
            {
                auto name = root.DisplayNameResource();
                auto s = winrt::to_string(name);
                std::wstring stemp = std::wstring(s.begin(), s.end());
                OutputDebugString(stemp.c_str());
            }
        }
    }
}
