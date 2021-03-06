// seller.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("潘若秋", ({ "seller" }) );
        set("title", "书局老板");
        set("gender", "男性" );
        set("age", 32);
        set("long", "潘老板长得很白净，一副读书人的老实相。\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set_skill("unarmed", 70);
        set_skill("dodge", 50);

        set("inquiry", ([
                "书局" : "为读书人办点事也是尽一份心意。", 
        ]) );

        set("vendor_goods", ([
		"嘉德文选":"/obj/book",
                "九韬":"/obj/book1",
                "太公辩":"/obj/book2",
                "梁父文集":"/obj/book3",
                "说律":"/obj/book4",
                "古文志":"/obj/book5",
                "乡书":"/obj/book6",
                "佾风斋诗集":"/obj/book7",
                "寒士列传":"/obj/book8",
                "水龙图注":"/obj/book9",
        	"说文解字": "/u/cloud/obj/literate_book",	
	]) );

        setup();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) ) {
                case 0:
                        say( "潘若秋迎上来，说道："
                                + RANK_D->query_respect(ob)
                                + "可是来买书的？\n");
                        break;
                case 1:
                        say( "潘若秋幽幽地叹了口气，说道：“作个读书人难啊！”。\n");
                        break;

		case 2:
			say( "潘若秋真聚精会神地看着书，似乎没注意你的到来。\n");
			break;

        }
}

