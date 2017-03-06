#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name(HIG "霏雪" NOR, ({ "ssss", "master","master ssss" }) );
        set("gender", "女性" );
        set("title",  "多情剑客" );
        set("age", 26);
        set("int", 30);
        set("per", 30);
        set("apprentice_available", 50);
        create_family("铁雪山庄", 1, "女庄主");
        set("long",
                "霏雪十八岁嫁得叶小叶后，就和丈夫行侠江湖，俩人刀剑合壁，\n"
                "天下无敌。正当俩人名声顶盛之时，又忽然退出江湖，隐居于此。\n"
                );
        set("combat_exp", 9999999);
        set("score", 90000);
        set_skill("unarmed", 100);
        set_skill("staff",80);
        set_skill("sword", 150);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("literate", 100);
        set_skill("dodge", 100);
        set_skill("throwing", 100);
       set_skill("perception", 100);


        set_skill("meihua-shou", 100);
        set_skill("deisword", 150);
        set_skill("qidaoforce", 150);
        set_skill("fall-steps", 100);

        map_skill("unarmed", "meihua-shou");
        map_skill("sword", "deisword");
        map_skill("force", "qidaoforce");
        map_skill("parry", "deisword");
        map_skill("dodge", "fall-steps");

        setup();
        carry_object(__DIR__"obj/yellowcloth")->wear();
        carry_object(__DIR__"obj/msword");
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 本庄主今天已经收了二十个弟子，不想再收徒了。");
        }
}
void do_recruit(object ob)
{
        if( (string)ob->query("gender") != "女性" )
          {      command("say 我只收女弟子，你还是去拜我的外子吧！");
          }
        else {

                command("smile");
                command("say 你日后必有大成！");
                command("smile");
                command("recruit " + ob->query("id") );
        }
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "legend");
        add("apprentice_availavble", -1);
}
int accept_fight(object me)
{
        object xiaocui;
        if( objectp(xiaocui = present("cui", environment(this_object()))) && living(xiaocui))
        {
        command("smile");
        command("say 还是让小翠来吧。");
        return 0;
        }
        else
                command("sigh");
                command("霏雪慢慢的从翠竹凳上站起来，放下了手中的紫砂杯。");
                command("wield wangsword");
                command("say 请！");
                call_out("do_unwie", 3);
                return 1;
}

int do_unwie()
{
        if( !this_object()->is_fighting()) 
        {
                command("unwield wangsword");
                message_vision("$N拿起茶杯浅啖一口，含情脉脉的望了叶小叶一眼，又坐在竹凳上。\n", this_object());
                command("smile");
                return 1;
        }
        else
                call_out("do_unwie", 3);
}
void init()
{
        add_action("do_killing", "kill");
}

int do_killing(string arg)
{

        object player, victim, weapon;
        string name;
        player = this_player();
        if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
        {
                name = victim->name();
                if( name == HIR "叶小叶" NOR)
                {
                message_vision("$N皱皱眉头。\n", this_object());
                message_vision("$N从赤皮剑鞘中抽出一把只有两指宽的虞姬剑握在手中。\n", this_object());
                weapon = present("wangsword", this_object());
                weapon->wield();
                this_object()->kill_ob(player);
                player->kill_ob(this_object());
                call_out("do_unwie", 3);
                return 0;
                }
                if( name == HIG "霏雪" NOR)
                {
                message_vision("$N皱皱眉头。\n", this_object());
                message_vision("$N从赤皮剑鞘中抽出一把只有两指宽的虞姬剑握在手中。\n", this_object());
                weapon = present("wangsword", this_object());
                weapon->wield();
                call_out("do_unwie", 3);
                return 0;
                }
                return 0;
        }
        return 0;
}
