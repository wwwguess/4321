inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
������һ��խС�����ң������ǰֻ��һ����ڵ�С·��һЩǬ�ݡ�
LONG
	);

        set("exits", ([ /* sizeof() == 3 */
            "east" : "/d/yulan/secrect1",
]));

	setup();
	replace_program(ROOM);
}
