// yuquan.c

inherit ROOM;

void create()
{
        set("short", "��ȪԺ");
	set("long", @LONG
�������ݺ����Ȫ�����������δ���ϣ�����ӵĵط�����Χ����ʮ��
������٣�ز�ö��ˣ�֦���пգ�����������ƣ��ഫ��ϣ������������
����ֲ��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : "/d/village/eexit",
]));
        set("no_clean_up", 0);
        set("objects", ([
                __DIR__"npc/teller": 1 ]) );

        setup();
        replace_program(ROOM);
}
 
