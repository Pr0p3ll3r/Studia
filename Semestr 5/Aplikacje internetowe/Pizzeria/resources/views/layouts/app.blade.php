<!DOCTYPE html>
<html lang="{{ str_replace('_', '-', app()->getLocale()) }}">
    <head>
        @include('elements.head')
        @yield('scripts')
    </head>
    <body>               
        @include('elements.navigation')

        {{ $slot }}

        @include('elements.footer')
    </body>
</html>