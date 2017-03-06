// Room: /d/island/boat.c

inherit ROOM;

void create()
{
        set("short", "小船");
        set("long", @LONG
冰山在大海中飘浮着，四周一片海蓝蓝，天气越来越冷。看来你
离中原越来越远了。水中不时有几条虾越出水面，溅起一片水花。突
然北方水天相接处有一个黑点，似乎是一个小岛。再使把劲往前划就
能到了。
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
 message_vision("$N使劲的划着冰山...\n",this_player());
 this_player()->receive_damage("kee",10);
 remove_call_out("arrive");
 call_out("arrive",10,this_player());
 return 1;
}

int arrive(object ob)
{
 ob->move(__DIR__"binghuo.c");
return 1;
}
