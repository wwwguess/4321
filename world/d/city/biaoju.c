// /d/city/biaoju

inherit ROOM;

void create()
{
        set("short", "��Զ�ܾ�");
        set("long",@LONG
����������Զ�ܾ���ھ���Ȼ���󣬵��ھ�ʦ��������ϣ�������
��֪������������������ͷ��ٲȻ���Ծ������������Ծӡ�
LONG
        );

        set("exits", ([
		"south":	__DIR__"street1",
                ]));

	set("objects", ([
		__DIR__"npc/chen":	1,
		]) );

        setup();
        set("valid_startroom", 1);
        replace_program(ROOM);
}

