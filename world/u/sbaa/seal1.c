// seal.c        write by sb 97.11.14

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_CLEAN_UP;


inherit ITEM;

void create()
{
	set_name("符咒", ({"seal"}) );
	set_weight(5);
	set("long",
		"这是一张画好的符咒，用 burn 将它贴在某人(或某物)身上。\n");
	set("unit", "张");
}

int unequip()
{
	set("equipped", 0);
	return 1;
}
void init()
{
add_action("do_warp", "burn");
}


int do_warp(string str)
{       
        object env,ob,where, *ob_list,me;
          int i;
       me=this_player();
        if (!str) return notify_fail("你要查谁？\n");
       ob = find_player(str);
	if( !ob ) ob = find_living(str);
	if( !ob || !me->visible(ob)) {
		str = resolve_path(me->query("cwd"), str);
		ob_list = children(str);
		for(i=0; i<sizeof(ob_list); i++) {
			if( !ob = environment(ob_list[i]) ) continue;
			printf("%O\n", ob );
		}
		return 1;
	}
	if (!ob) return notify_fail("现在没这个人.\n");
	where = environment(ob);
	if (!where) return notify_fail("这个人不知道在那里耶...\n");
     	message_vision("$N把天眼通符贴在眼前，呼的一下符烧起来了！！\n",me );
	printf("%s(%s)现在在%s.\n",
		(string)ob->name(),
		(string)ob->query("id"),
		(string)where->query("short"));
	//	(string)file_name(where));
   	destruct(this_object());
	return 1;
}

