<x-app-layout>
    <section class="page-section cta">
        <div class="container">
            <div class="row">
                <div class="mx-auto space-y-6">
                    <div class="cta-inner bg-faded text-center rounded">
                        <h2 class="section-heading mb-5">
                            <span class="section-heading-lower fw-bold">Koszyk</span>
                        </h2>
                        <div class="table-responsive">
                            <table id="koszyk" class="table table-primary">
                                <tr> 
                                    <td class="col-md-1">Ilość</td> 
                                    <td class="col-md-3">Nazwa</td>
                                    <td class="col-md-2">Wielkość</td> 
                                    <td class="col-md-2">Zmień ilość</td> 
                                    <td class="col-md-2">Cena</td> 
                                    <td class="col-md-1">Usuń</td> 
                                </tr>
                                @foreach($cart as $id => $item)
                                <tr> 
                                    <td class="col-md-1">{{ $item['quantity'] }}x</td> 
                                    <td class="col-md-3">{{ $item['name'] }}</td>
                                    <td class="col-md-2">{{ $item['size'] }}cm</td> 
                                    <td class="col-md-2"> 
                                        <form class="form-check form-check-inline" action="{{ route('cart.update') }}" method="POST">
                                            @csrf
                                            <input type="hidden" value="{{ $id }}" name="id">
                                            <input type="hidden" value="1" name="quantity">
                                            <button class="btn btn-primary bi-plus"></button>
                                        </form>                                      
                                        <form class="form-check form-check-inline" action="{{ route('cart.update') }}" method="POST">
                                            @csrf
                                            <input type="hidden" value="{{ $id }}" name="id">
                                            <input type="hidden" value="-1" name="quantity">
                                            <button class="btn btn-primary bi-dash"></button> 
                                        </form>
                                    </td> 
                                    <td class="col-md-2">{{ $item['price'] }}zł</td> 
                                    <td class="col-md-2"> 
                                        <form action="{{ route('cart.remove') }}" method="POST">
                                            @csrf
                                            <input type="hidden" value="{{ $id }}" name="id">
                                            <button class="btn btn-primary bi-trash"></button> 
                                        </form>
                                    </td> 
                                </tr>
                                @endforeach
                                <tr> 
                                    <td colspan="6" class="text-center">
                                        <h4>
                                            <span class="section-heading-lower fw-bold">Razem do zapłaty: {{ \App\Http\Controllers\CartController::getTotalPrice() }} zł</span>
                                        </h4>
                                    </td>
                                </tr>
                            </table>	
                        </div>						
                    </div>
                    <div class="cta-inner bg-faded text-center rounded">
                        <h2 class="section-heading mb-5">
                            <span class="section-heading-lower fw-bold">Dane kontaktowe</span>
                        </h2>
                        <form method="POST" action="{{ route('order.send') }}">
                            @csrf
                            <div class="table-responsive">
                                <table class="table table-primary">          
                                    <tr>
                                        <td>
                                    <x-input-label for="name" :value="__('Name')" />
                                    <x-text-input id="name" name="name" type="text" class="mt-1 block w-full form-control" :value="old('name', Auth::user()->name)" disabled />
                                    <x-input-error class="mt-2" :messages="$errors->get('name')" />
                                    </td>
                                    <td>
                                    <x-input-label for="phone" :value="__('Phone')" />
                                    <x-text-input id="phone" name="phone" type="text" class="mt-1 block w-full form-control" :value="old('phone', Auth::user()->phone)" disabled />
                                    <x-input-error class="mt-2" :messages="$errors->get('phone')" />
                                    </td>
                                    <td>
                                    <x-input-label for="email" :value="__('Email')" />
                                    <x-text-input id="email" name="email" type="email" class="mt-1 block w-full form-control" :value="old('email', Auth::user()->email)" disabled />
                                    <x-input-error class="mt-2" :messages="$errors->get('email')" />
                                    </td>
                                    </tr>
                                    <tr>
                                        <td>
                                            <?php 
                                            $address = DB::table('order_addresses')
                                                    ->join('orders', 'order_addresses.order_id', '=', 'orders.id')
                                                    ->join('users', 'orders.user_id', '=', 'users.id')
                                                    ->where('users.id', Auth::id())
                                                    ->select('street', 'houseNumber', 'apartmentNumber')
                                                    ->latest('orders.created_at')                                            
                                                    ->first();
                                            ?>                              
                                    <x-input-label for="street" :value="__('Street')" />
                                    <x-text-input id="street" name="street" type="text" class="mt-1 block w-full form-control" :value="old('street', $address->street ?? '')" 
                                                  pattern="[A-Za-z ]+" maxlength="255" required autocomplete="street" />
                                    <x-input-error class="mt-2" :messages="$errors->get('street')" />
                                    </td>
                                    <td>
                                    <x-input-label for="houseNumber" :value="__('House Number')" />
                                    <x-text-input id="houseNumber" name="houseNumber" type="text" class="mt-1 block w-full form-control" :value="old('houseNumber', $address->houseNumber ?? '')" 
                                                  pattern="[A-Za-z0-9]+" maxlength="5" required autocomplete="houseNumber" />
                                    <x-input-error class="mt-2" :messages="$errors->get('houseNumber')" />
                                    </td>
                                    <td>
                                    <x-input-label for="apartmentNumber" :value="__('Apartment Number')" />
                                    <x-text-input id="apartmentNumber" name="apartmentNumber" type="text" class="mt-1 block w-full form-control" :value="old('apartmentNumber', $address->apartmentNumber ?? '')" 
                                                  pattern="[A-Za-z0-9]+" maxlength="5" autocomplete="apartmentNumber" />
                                    </td>
                                    </tr>                                                            
                                    <tr>
                                        <td colspan="3">
                                            <textarea placeholder="Komentarz" class="form-control form-control-sm" name="comment" id="comment" maxlength="255"></textarea> 
                                        </td>
                                    </tr>
                                    <tr class="text-center">
                                        <td colspan="3">
                                            <h4><b>Jak chcesz zapłacić?</b></h4>
                                            <input class="form-check-input" type="radio" value="gotowka" name="payment" checked />
                                            <label for="gotowka">Gotówka</label><br>
                                            <input class="form-check-input" type="radio" value="karta" name="payment"/>
                                            <label for="karta">Karta płatnicza</label><br>
                                            <input class="form-check-input" type="radio" value="online" name="payment"/>
                                            <label for="online">Płatność online</label><br><br>
                                            <div>
                                                <input class="form-check-input" type="checkbox" id="rules" name="regulamin" required />
                                                <label for="regulamin">*Akceptuję regulamin</label>
                                            </div>
                                        </td>												
                                    </tr>
                                </table>
                            </div>													
                            <input class="btn btn-primary" type="submit" id="zamawiam" value="Zamawiam"/> 
                        </form>
                    </div>
                </div>
            </div>
        </div>
    </section>
</x-app-layout>