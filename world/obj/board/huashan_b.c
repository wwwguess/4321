// /clone/board/huashan_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("华山弟子留言板", ({ "board" }) );
        set("location", "/d/huashan/buwei1");
        set("board_id", "huashan_b");
        set("long", "这是一个供华山弟子交流的留言板。\n" );
        setup();
        set("capacity", 30);
        replace_program(BULLETIN_BOARD);
}
