// Room: /d/new_taohua/mufa.c     

inherit ROOM;

void create()
{
        set("short", "木筏");
        set("long", @LONG
这是你做的小木筏，你要靠它划回桃花岛了。
LONG
        );

        setup();
}

void init()
{
 add_action("do_boating","boating");
}

int do_boating()
{
 message_vision("$N使劲的划着木筏...\n",this_player());
 this_player()->receive_damage("kee",10);
 remove_call_out("arrive");
 call_out("arrive",10,this_player());
 return 1;
}

int arrive(object ob)
{
 ob->move(__DIR__"haitan1.c");
return 1;
}
