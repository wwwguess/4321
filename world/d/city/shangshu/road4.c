// /d/city/shangshu/road4

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long",@LONG
���������鸮��һ��Ƨ����С·�ϡ�����С·�����Ż�԰��һ��
�������ӻ��ݣ�ƽ�������������ˡ�����Ļ�԰������Զ�ˣ������
�Ŷ��Ѿ�����ķ�����������Ŀ�������Ǹ��ʵ�Ժǽ��
LONG
        );

        set("exits", ([
		"west":		__DIR__"feiwu",
		"east":		__DIR__"huayuan",
                ]));

	set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

