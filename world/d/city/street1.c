// Room: /d/city/street1.c

inherit ROOM;

void create()
{
        set("short", "��ʦ����");
        set("long", @LONG
�����Ǿ�ʦ���ֵı��Ρ���������һ����Ժ�ӣ�Ժ�����Ÿ��ϸ�
�ϸߵ���ˣ�����һ������ġ��ڡ��֣�����Զ�Ϳ��Կ������ھֵ�
�����ƺ��ܺã������ﲻ����������ׯ�ϵ������š�������ȥ������
�������š�
LONG
        );
        set("exits", ([ 
		"north":	__DIR__"biaoju",
		"south":	__DIR__"street2",
		"west":		__DIR__"shenwumen",
		]));

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

