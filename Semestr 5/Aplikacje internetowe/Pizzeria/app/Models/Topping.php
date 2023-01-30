<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;
use App\Models\Pizza;

class Topping extends Model
{
    use HasFactory;
    
    public function pizzas()
    {
        return $this->belongsToMany("App\Models\Pizza");
    }
}
