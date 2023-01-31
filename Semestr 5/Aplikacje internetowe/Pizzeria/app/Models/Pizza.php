<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Pizza extends Model
{
    use HasFactory;
    
    protected $fillable = [
        'name',
        'priceFor32',
        'priceFor42'
    ];
    
    public function toppings()
    {
        return $this->belongsToMany('App\Models\Topping');
    }
    
    public function cart()
    {
        return $this->hasOne('App\Models\OrderItem');
    }
}
