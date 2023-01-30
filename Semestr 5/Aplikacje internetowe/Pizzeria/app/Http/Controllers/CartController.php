<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Pizza;

class CartController extends Controller 
{
    public function index() 
    {
        $pizzas = Pizza::all();
        return view('pages.menu', ['pizzas' => $pizzas]);
    }

    public function cart() 
    {
        $cart = session('cart');
        if(empty($cart)){
            $pizzas = Pizza::all();
            return view('pages.menu', ['pizzas' => $pizzas]);           
        }
        return view('pages.cart', ['cart' => $cart]);
    }

    public function addToCart(Request $request) 
    {
        $pizza = Pizza::find($request->id);
        $cart = session('cart');
        if($request->size == "32")
        {
            $p_id = $request->id + 32;
            $price = $pizza->priceFor32;
        }
        else
        {
            $p_id = $request->id + 42;
            $price = $pizza->priceFor42;
        }
        
        if (isset($cart[$p_id])) 
        {
            $cart[$p_id]['quantity']++;
        } 
        else 
        {
            $cart[$p_id] = [
                'id' => $request->id,
                'name' => $pizza->name,
                'size' => $request->size,
                'quantity' => 1,
                'price' => $price
            ];
        }
        session(['cart' => $cart]);
        return redirect()->back();
    }

    public function update(Request $request) 
    {
        if ($request->id && $request->quantity) 
        {
            $cart = session('cart');
            $cart[$request->id]["quantity"] += $request->quantity;
            if($cart[$request->id]["quantity"] != 0)
                session(['cart' => $cart]);
        }
        return redirect()->back();
    }

    public function remove(Request $request) 
    {
        if ($request->id) 
        {
            $cart = session('cart');
            if (isset($cart[$request->id])) 
            {
                unset($cart[$request->id]);
                session(['cart' => $cart]);
            }
        }
        if (!empty($cart)) {
            return redirect()->back();
        }
        else {     
            return redirect('/'); 
        }
    }
    
    public static function getTotalPrice()
    {
        $cart = session('cart');
        $total = 0;
        if(isset($cart))
        {
            foreach($cart as $item)
            {
                $total += $item['price'] * $item['quantity'];
            }
        }       
        return $total;
    }
}
