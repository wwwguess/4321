// Room: /u/cloud/nwroad1.c

inherit ROOM;

void create()
{
        set("short", "���г�");
        set("long", @LONG
�����������ı��г������򱱾�������ˡ�
    һ�ɲ������������ϵ���ζ�˱Ƕ�����������������Ÿ�ţͷ;
�����ǼҶ���Ĳ�¥����������ʮ�ֻ��ۡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/u/cloud/butchery",
  "north" : "/u/cloud/entrance",
  "south" : "/u/cloud/nwroad2",
  "east" : "/u/cloud/tearoom",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

