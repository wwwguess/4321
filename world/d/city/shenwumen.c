// Room: /d/city/shenwumen.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�������Ͻ��ǵı���--�����š�����Ĵ���ͨ���Ͻ��ǣ�������
���ٿ������ϲ��Ŵ�����������ʿ�����ء��������ǻʼҼ�̳������
һ��һ�ȼ���ʱ���ܺ����塣������ĵ�·�ֱ�ͨ��ʦ������·��
LONG
        );
        set("exits", ([ 
		"north":	__DIR__"jitan",
//		"south":	__DIR__"zijincheng",
		"east":		__DIR__"street1",
		"west":		__DIR__"street6",
		]));

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

