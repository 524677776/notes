%% @author Administrator
%% @doc @todo Add description to shop2.


-module(shop2).

%% ====================================================================
%% API functions
%% ====================================================================
-export([total/1]).
-import(lists, [map/2, sum/1]).



%% ====================================================================
%% Internal functions
%% ====================================================================
total(L)	->
	sum(map(fun({What, N}) -> shop:cost(What) * N end, L)).

