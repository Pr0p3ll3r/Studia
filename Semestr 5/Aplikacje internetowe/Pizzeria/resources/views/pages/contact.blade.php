<x-app-layout>
    <script>
        window.onload = function ()
        {
            pokazMape();
            currentDay();
        };
    </script>
    <section class="page-section-top cta">
        <div class="container">
            <div class="row">
                <div class="col-xl-9 mx-auto">
                    <div class="cta-inner bg-faded text-center rounded">
                        <h2 class="section-heading mb-5">
                            <span class="section-heading-lower fw-bold">Godziny otwarcia</span>
                        </h2>
                        <ul class="list-unstyled list-hours mb-5 text-left mx-auto">
                            <li class="list-unstyled-item list-hours-item d-flex">
                                Poniedziałek
                                <span class="ms-auto">10 - 22</span>
                            </li>
                            <li class="list-unstyled-item list-hours-item d-flex">
                                Wtorek
                                <span class="ms-auto">10 - 22</span>
                            </li>
                            <li class="list-unstyled-item list-hours-item d-flex">
                                Środa
                                <span class="ms-auto">10 - 22</span>
                            </li>
                            <li class="list-unstyled-item list-hours-item d-flex">
                                Czwartek
                                <span class="ms-auto">10 - 22</span>
                            </li>
                            <li class="list-unstyled-item list-hours-item d-flex">
                                Piątek
                                <span class="ms-auto">10 - 23</span>
                            </li>
                            <li class="list-unstyled-item list-hours-item d-flex">
                                Sobota
                                <span class="ms-auto">12 - 23</span>
                            </li>
                            <li class="list-unstyled-item list-hours-item d-flex">
                                Niedziela
                                <span class="ms-auto">12 - 22</span>
                            </li>
                        </ul>
                        <p class="address mb-5">
                            <em>
                                <strong>ul. Nadbystrzycka 38 D</strong>
                                <br />
                                20 – 618 Lublin
                            </em>
                        </p>
                        <p class="address mb-5">
                            <em>
                                <strong>Email:</strong>
                                <br />
                                <strong><a href="mailto:info@poppizza.pl">info@poppizza.pl</a></strong>
                            </em>
                        </p>
                        <p class="address mb-0">
                            <em>Zapraszamy do składania zamówień pod numerem telefonu:</em>
                            <br />
                            <strong class="fw-bold">12 345 67 89</strong>
                        </p>
                    </div>
                </div>
            </div>
        </div>
    </section>
    <div id="mapa">
        <!-- tu będzie mapa -->
    </div>
</x-app-layout>