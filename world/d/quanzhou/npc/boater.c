// boater.c

inherit NPC;

void create()
{
        set_name("老船夫", ({ "boater" }) );
        set("gender", "男性" );
        set("age", 58);
        set("shen_type", 0);

        set("long",
                "一位饱经沧桑的老渔夫，脸上的皱纹说明了一切。\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set_skill("unarmed", 100);
        
        set("inquiry", ([
                "桃花岛" : "桃花岛，出海往东就是了。\n"
                ])
           );

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
    add_action("do_boat","boat");
        
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
        case 0:
                say( "老船夫说到：这位" + RANK_D->query_respect(ob)
                        + "，坐船(boat)吗？\n");
                break;
        case 1:
                say( "老船夫自言自语的说:这几天到桃花岛的人这么这么多？\n");
                break;
        }
}

int do_boat(string arg)
{
 if(arg!="桃花岛"){
                   command("say 去别处我不借船！");
                   return 1;
                   }
 command("say 一路多加小心。");
 message_vision("$N被老船夫带进了一条小船。\n",this_player());
 this_player()->move("/d/taohua/boat.c");
 return 1;
}
