<x-app-layout>
    <div class="page-section cta">
        <div class="container">
            <div class="row">
                <div class="col-xl-9 mx-auto">
                    <div class="cta-inner bg-faded text-center rounded">
                        <span class="section-heading-lower fw-bold">{{ __("You're logged in!") }}</span>
                        <div class="flex items-center justify-center mt-4">
                            <a class="underline text-sm text-gray-600 dark:text-gray-400 hover:text-gray-900 dark:hover:text-gray-100 rounded-md focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-indigo-500 dark:focus:ring-offset-gray-800" href="{{ url('profile') }}">
                                {{ __('Profile') }}                
                            </a>

                            <a class="ml-3 underline text-sm text-gray-600 dark:text-gray-400 hover:text-gray-900 dark:hover:text-gray-100 rounded-md focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-indigo-500 dark:focus:ring-offset-gray-800" href="{{ url('orders') }}">
                                {{ __('Twoje zamówienia') }}
                            </a>

                            <form action="{{ route('logout') }}" method="POST">
                                @csrf
                                <x-primary-button class="ml-3">
                                    {{ __('Log Out') }}
                                </x-primary-button>
                            </form>
                        </div>
                    </div>  
                </div>
            </div>
        </div>
    </div>
</x-app-layout>
