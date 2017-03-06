// keeper.c

inherit ITEM;

void init()
{
	add_action("do_put", "juan");}
void create()
{
	set_name("功\德箱", ({ "denotation box", "box" }) );
	set("unit", "个");
	set("long",
		"这是寺庙接受善男信女捐献香油钱的功\德箱，你可以把想捐的钱\n"
		"放进去。\n");
	set("value", 1);
	set("no_get", 1);
	set_max_encumbrance(10000);
}

int
 do_put(string arg)
{
	int val;
	object who,ob;
        if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("你要捐什麽物品？\n");
            ob = present(arg, this_player());

	val=ob->value();
       who=this_player();
	//if( !who = this_player() ) return;

	//if( !val  ) return;

	//if( val > 100 ) {
	//	if (who->query("bellicosity") > 0)
	//	&&	(random(val/10) > (int)who->query("kar")) )
			who->add("bellicosity", - (val/10) );
                      val=val/10;
               write(who->name()+"的杀气降低了"+val+"点.\n");	

	seteuid(getuid());
	destruct(ob);
 return 1;
}
