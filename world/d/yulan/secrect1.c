inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
������һ��խС�����ң������ǰֻ��һ����ڵ�С·��һЩǬ�ݡ�
LONG
	);

        set("exits", ([ /* sizeof() == 3 */
            "west" : "/d/yulan/secrect",
            "east" : "/d/yulan/secrect2",
]));

	setup();
	replace_program(ROOM);
}
