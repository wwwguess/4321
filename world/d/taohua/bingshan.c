// Room: /d/island/boat.c

inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
��ɽ�ڴ���Ʈ���ţ�����һƬ������������Խ��Խ�䡣������
����ԭԽ��ԽԶ�ˡ�ˮ�в�ʱ�м���ϺԽ��ˮ�棬����һƬˮ����ͻ
Ȼ����ˮ����Ӵ���һ���ڵ㣬�ƺ���һ��С������ʹ�Ѿ���ǰ����
�ܵ��ˡ�
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
 message_vision("$Nʹ���Ļ��ű�ɽ...\n",this_player());
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
