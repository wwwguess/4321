// Room: /u/cloud/wroad2.c

inherit ROOM;

void create()
{
        set("short", "�����ֵ�");
        set("long", @LONG
������������������߾���ʮ��·�ڡ������Ժ�����������֣���
���кܶ��˵����ӡ��������ӻ��̣������Ų���������򿪡�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/u/cloud/wroad1",
  "south" : "/u/cloud/monky",
  "east" : "/u/cloud/cross",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

