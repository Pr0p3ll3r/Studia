<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
<meta name="csrf-token" content="{{ csrf_token() }}">

<title>{{ config('app.name', 'Pop Pizza') }}</title>

@vite(['resources/css/app.css', 'resources/js/app.js'])
<script src="{{ URL::asset('js/scripts.js'); }}"></script>
<script src="https://maps.google.com/maps/api/js?sensor=false"></script>

<link rel="icon" href="{{ URL::asset('favicon.ico') }}" type="image/x-icon">

<link href="https://fonts.googleapis.com/css?family=Raleway:900,900i" rel="stylesheet">

<link href="{{ URL::asset('css/style.css'); }}" rel="stylesheet">
<link href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css" rel="stylesheet">

<script>
window.onscroll = function () {
    scrollFunction();
};
</script>