<header>
    <h1 class="site-heading text-center text-faded d-none d-lg-block">
        <span class="site-heading-upper mb-3">Szybko i smacznie</span>
        <span class="site-heading-lower text-primary fw-bold mb-3">Pop Pizza</span>
    </h1>
</header>
<!-- Navigation-->
<nav class="navbar navbar-expand-lg navbar-dark py-lg-4" id="mainNav">
    <div class="container">
        <a class="navbar-brand text-uppercase fw-bold d-lg-none" href="{{ url('/') }}">Pop Pizza</a>
        <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation"><span class="navbar-toggler-icon"></span></button>
        <div class="collapse navbar-collapse" id="navbarSupportedContent">
            <ul class="navbar-nav mx-auto">
                <li class="nav-item px-lg-4"><a class="nav-link text-uppercase" href="{{ url('/') }}">Strona główna</a></li>
                <li class="nav-item px-lg-4"><a class="nav-link text-uppercase" href="{{ url('menu') }}">Menu</a></li>
                <li class="nav-item px-lg-4"><a class="nav-link text-uppercase" href="{{ url('contact') }}">Kontakt</a></li>             
                <li class="nav-item px-lg-4"><a class="nav-link text-uppercase" href="{{ url('login') }}">Konto</a></li>
                <li class="nav-item px-lg-4">
                    @if(session('cart'))
                    <a class="btn btn-outline-light" href="{{ url('cart') }}">
                    @else
                        <a class="btn btn-outline-light disabled" href="{{ url('cart') }}">
                            @endif
                            <b class="bi-cart-fill me-1 text-white marg"></b>                           
                            <span class="badge bg-dark text-white ms-1 rounded-pill">{{ \App\Http\Controllers\CartController::getTotalPrice() }} zł</span>                                             
                        </a>
                </li>
            </ul>
        </div>  
    </div>
</nav>