<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;
use App\Models\Pizza;

class Topping extends Model
{
    use HasFactory;
    
    protected $fillable = [
        'name'
    ];
    
    public function pizzas()
    {
        return $this->hasMany("App\Models\Pizza");
    }
}
