// Room: /d/island/boat.c

inherit ROOM;

void create()
{
        set("short", "小船");
        set("long", @LONG
    你划着小船在大海中行进，四周一片海蓝蓝。水中不时有几条虾越出水面，溅起一
片水花。向西面看，隐约可以看到大陆的轮廓。东南方水天相接处有一个黑点，似乎是
一个小岛。再使把劲往前划(boating)就能到了。
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
 message_vision("$N使劲的划着船...\n",this_player());
 this_player()->receive_damage("kee",30);
 remove_call_out("arrive");
  call_out("arrive",2,this_player());
 return 1;
}

int arrive(object ob)
{
 ob->move(__DIR__"haibian.c");
return 1;
}
