// /d/city/shangshu/road3

inherit ROOM;

void create()
{
        set("short", "��԰С��");
        set("long",@LONG
���������鸮�Ļ�԰С����С�����Ϸ����ǻ�԰�����������
Ʈ������ʹ�˾�����񡣳�����С���Ķ��棬��������ȥ�����鸮��
ͥԺ��
LONG
        );

        set("exits", ([
		"north":	__DIR__"yuan",
		"south":	__DIR__"huayuan",
		"east":		__DIR__"chufang",
                ]));

        set("outdoors", "city");

 	setup();
        replace_program(ROOM);
}

