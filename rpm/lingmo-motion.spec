Name:           lingmo-motion
Version:        1.0.0
Release:        1%{?dist}
Summary:        Lingmo Motion System

License:        GPL-3.0-or-later
URL:            https://github.com/lingmo-os/lingmo-motion
Source0:        %{url}/archive/v%{version}/%{name}-%{version}.tar.gz

BuildRequires:  cmake >= 3.20
BuildRequires:  gcc-c++
BuildRequires:  qt6-qtbase-devel >= 6.5
BuildRequires:  qt6-qtdeclarative-devel


%description
Lingmo Motion System for Lingmo Desktop.

%prep
%autosetup -n %{name}-%{version}

%build
%cmake
%cmake_build

%install
%cmake_install

%files
%license LICENSE
%doc README.md

%changelog
* Wed Jul 10 2026 Lingmo OS Team <team@lingmo.org> - 1.0.0-1
- Initial release
