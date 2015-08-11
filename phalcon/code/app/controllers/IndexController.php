<?php

class IndexController extends ControllerBase
{

    public function indexAction()
    {
    	echo 'hello world!';
    	exit;
    }

    public function addAction()
    {
    	$user = new Users();
    	$user->name = 'zhang3';
    	$user->email = 'a@a.com';
		if ($user->save() == false) {
		    echo "Umh, We can't store user right now: \n";
		    foreach ($user->getMessages() as $message) {
		        echo $message, "\n";
		    }
		} else {
		    echo "Great, a new user was saved successfully!";
		}
    }

    public function getAction()
    {
		$users = Users::find();
		echo "There are ", count($users), "\n";
    }

    public function delAction()
    {
    	$users = Users::findFirst();

		if ($users != false) {
		    if ($users->delete() == false) {
		        echo "Sorry, we can't delete the users right now: \n";

		        foreach ($users->getMessages() as $message) {
		            echo $message, "\n";
		        }
		    } else {
		        echo "The users was deleted successfully!";
		    }
		}
    }

}

