// Room: /d/heimuya/.c
// write by: Www
// date 97/01/25

inherit ROOM;

void create()
{
        set("short","������վ");
        set("long", @LONG
����һ��ȥ��������ר����վ����Ǯ�Ϳ������ٵ����������򱱲���Ҫ�ھ���·
���߰�Сʱ����վ�����п�����(sign)��
LONG
        );

        set("exits", ([
		"north" : __DIR__"jbdd",
                "west"  : __DIR__"bdcm",
        ]));

        set("item_desc", ([ 
  		"sign" : "�ڴ˽� 1 silver ���䳤�Ϳ�ȥ������\n",
	]));

	set("objects", ([
		"/d/heimuya/yizhang1" : 1,
	]));

        set("outdoors", "heimuya");
        setup();
        replace_program(ROOM);
}

