// /d/city/street5

inherit ROOM;

void create()
{
        set("short", "��ʦ����");
        set("long",@LONG 
�����������ھ�ʦ�Ľֵ��ϣ������Ǿ�ʦ�������ġ�̫�׾�¥����
��¥�����̾��������ﶼ�У������������ڶ������߽������Ͻ��ǵ�
��ǽ(wall)���ֵ����ϱ����������š�
LONG
        );

        set("exits", ([
		"west" :	__DIR__"jiulou",
		"south" : 	__DIR__"street4",
		"north" :	__DIR__"street6",
		]));
        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

