// Room: /d/island/boat.c

inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
    �㻮��С���ڴ����н�������һƬ��������ˮ�в�ʱ�м���ϺԽ��ˮ�棬����һ
Ƭˮ���������濴����Լ���Կ�����½�����������Ϸ�ˮ����Ӵ���һ���ڵ㣬�ƺ���
һ��С������ʹ�Ѿ���ǰ��(boating)���ܵ��ˡ�
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
 message_vision("$Nʹ���Ļ��Ŵ�...\n",this_player());
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
