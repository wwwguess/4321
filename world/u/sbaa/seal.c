// seal.c write by sb 97.11.14

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


int do_warp(string tar)
{       
        object env,who;
       
       
        who=this_player();
    //  if( who && who!=this_player() )
          //  return notify_fail("阴界传送符只能对自己使用。\n");

    //  env = environment(this_player());
      message_vision( HIB"$N祭起一张阴界传送符。\n\n",who);             
   message_vision("忽然四周吹起了一阵凉飕飕的阴风，阴风之中彷佛有许多人影在晃动...\n\n",who);
                message_vision("然後一阵火光突然爆起！\n" NOR,who);
        //OP_CMD->main(this_player(), "all");
     
                   message_vision(
                CYN "可是....$N已经不见了。\n"NOR,who);
        message("vision",
                CYN 
"你只觉得身子不断下坠，一直下坠，一直下坠，一直下坠，一直下坠 .....\n\n"
                NOR     
"不知道什麽时候，你发现你其实一直都站在坚硬的地面上，可是四周的景物\n\n"
                        "却不一样了....\n", this_player() );
      who->move(DEATH_ROOM);

        destruct(this_object());
        return 1;
}
