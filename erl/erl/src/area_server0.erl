%% @author Administrator
%% @doc @todo Add description to area_server0.


-module(area_server0).

%% ====================================================================
%% API functions
%% ====================================================================
-export([loop/0, rpc/2]).

rpc(Pid, Request)	->
	Pid ! {self(), Request},
	receive
		Response ->
			Response
	end.


%% ====================================================================
%% Internal functions
%% ====================================================================

loop() ->
	receive
		{From, {rectangle, Width, Ht}}	->
			From ! Width * Ht,
			loop();
		{From , {circle, R}}	->
			From ! 3.14159 * R * R,
			loop();
		{From, Other}	->
			From! {error, Other},
			loop()
	end.