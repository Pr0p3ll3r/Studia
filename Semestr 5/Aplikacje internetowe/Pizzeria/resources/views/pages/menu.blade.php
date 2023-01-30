<x-app-layout>
    <section class="py-5">
        <div class="container px-4 px-lg-5 mt-5">
            <div class="row gx-4 gx-lg-5 row-cols-2 row-cols-md-3 row-cols-xl-4 justify-content-center">    
                @foreach($pizzas as $pizza)
                <form method="post" action="{{ route('cart.add') }}">
                    @csrf
                    <div class="col mb-5"> 
                        <!-- Pizza image-->
                        <img class="card-img-top" src="./images/pizza/{{$pizza->name}}.png" alt="Pizza {{$pizza->name}}" />
                        <!-- Pizza details-->
                        <div class="card-body p-4">
                            <div class="text-center text-white">
                                <!-- Pizza name-->
                                <h5 class="fw-bolder">{{$pizza->name}}</h5>
                                <!-- Pizza toppings-->
                                @if($pizza->toppings->isEmpty())
                                    sos, ser, przyprawy
                                @else
                                   sos, ser, przyprawy,
                                @endif
                                
                                @foreach ($pizza->toppings as $topping)                                    
                                @if ($loop->last)
                                {{$topping->name}}
                                @else  
                                {{$topping->name}},
                                @endif     
                                @endforeach 
                            </div>
                        </div>
                        <select name="size" class="form-select btn-primary text-center">
                            <option value="32">32cm - {{$pizza->priceFor32}}zł</option>
                            <option value="42">42cm - {{$pizza->priceFor42}}zł</option>
                        </select><br>
                        <input type="hidden" value="{{ $pizza->id }}" name="id">
                        <!-- Pizza actions-->
                        <div class="card-footer p-4 pt-0 border-top-0 bg-transparent">
                            <div class="text-center"><button type="submit" class="btn btn-primary">Dodaj do koszyka</button></div>
                        </div>                      
                    </div>
                </form>
                @endforeach
            </div>
        </div>
    </section>
</x-app-layout>