<?php

use App\Http\Controllers\ProfileController;
use App\Http\Controllers\OrderController;
use App\Http\Controllers\CartController;
use Illuminate\Support\Facades\Route;

/*
  |--------------------------------------------------------------------------
  | Web Routes
  |--------------------------------------------------------------------------
  |
  | Here is where you can register web routes for your application. These
  | routes are loaded by the RouteServiceProvider within a group which
  | contains the "web" middleware group. Now create something great!
  |
 */

Route::get('/', function () { return view('pages.welcome'); });
Route::get('/contact', function () { return view('pages.contact'); });
Route::get('/menu', [CartController::class, 'index']);

Route::middleware('auth')->group(function () {
    Route::get('dashboard', function () { return view('pages.dashboard'); });
    
    Route::get('/profile', [ProfileController::class, 'edit'])->name('profile.edit');
    Route::patch('/profile', [ProfileController::class, 'update'])->name('profile.update');
    Route::delete('/profile', [ProfileController::class, 'destroy'])->name('profile.destroy');

    Route::get('/cart', [CartController::class, 'cart'])->name('cart.list');
    Route::post('/addtocart', [CartController::class, 'addToCart'])->name('cart.add');
    Route::post('/updatecart', [CartController::class, 'update'])->name('cart.update');
    Route::post('/removefromcart', [CartController::class, 'remove'])->name('cart.remove');

    Route::get('/orders', [OrderController::class, 'create']);
    Route::post('sendorder', [OrderController::class, 'store'])->name('order.send');
    Route::get('/ordered', function () { return view('pages.ordered'); });
});

require __DIR__ . '/auth.php';
