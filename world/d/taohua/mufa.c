// Room: /d/new_taohua/mufa.c     

inherit ROOM;

void create()
{
        set("short", "ľ��");
        set("long", @LONG
����������Сľ������Ҫ���������һ����ˡ�
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
 message_vision("$Nʹ���Ļ���ľ��...\n",this_player());
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
