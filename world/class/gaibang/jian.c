#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void consider();
int ask_me_1();
int ask_me_2();

void create()
{
        set_name("简长老", ({"jian zhanglao", "jian", "zhanglao"}));
        set("title", "丐帮九袋长老");
        set("nickname", GRN "执法长老" NOR);
        set("title",MAG "丐帮" NOR + YEL "九袋" NOR+ MAG "长老" NOR);
        set("gender", "男性");
        set("age", 50);
        set("long",
                "简长老是丐邦的执法长老，代帮主执掌法刀以及青竹令等。\n"
                "他向来嫉恶如仇，弟子中有谁犯过，出手决不容情。\n");

        set("attitude", "peaceful");

        set("str", 24);
        set("int", 20);
        set("con", 24);
        set("dex", 20);

        set("kee", 2000);
        set("max_kee", 2000);
        set("gin", 1000);
        set("max_gin", 100);
        set("force", 1500);
        set("max_force", 1500);
        set("force_factor", 120);

        set("combat_exp", 1200000);
        set("score", 20000);

        set_skill("force", 125); // 基本内功
        set_skill("huntian-qigong", 120); // 混天气功
        set_skill("strike", 120); // 基本掌法
        set_skill("xianglong-zhang", 115); // 降龙十八掌
        set_skill("dodge", 120); // 基本躲闪
        set_skill("xiaoyaoyou", 125); // 逍遥游
        set_skill("parry", 115); // 基本招架
        set_skill("staff", 120); // 基本棍杖

        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");

        prepare_skill("strike", "xianglong-zhang");

        create_family("丐帮", 18, "九袋长老");

        set("inquiry", ([
                "青竹令":     (: ask_me_1 :),
                "升袋"  :     (: ask_me_2 :),
                "升级"  :     (: ask_me_2 :),
                "晋级"  :     (: ask_me_2 :)
        ]));
 
        setup();
}

init()
{
        object ob;
	object obj;
	int i;
        mapping myfam;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                myfam = (mapping)ob->query("family");
                if ((!myfam || myfam["family_name"] != "丐帮") &&
                        (!wizardp(ob))) {
                        remove_call_out("saying");
                        call_out("saying",2,ob);
                }
        }
         if ((string)ob->query("family/family_name")=="丐帮" && !present("bu dai", ob))
        {
                command("say 不小心死了吧！");
                   for(i=1; i<= ob->query("dai"); i++)
                {
                        obj=new("/d/gaibang/obj/gaibang-bag");
                	obj->move(ob);
                }
        }
}

void saying(object ob)
{
        if (!ob || environment(ob) != environment())
                return;

        message_vision("\n简长老看了$N一眼，冷冷地说到：“洪帮主他老人家说我不该"
            "随意责打丐帮弟子，\n你又不属我丐帮，我打你总可以吧？”\n"
            "说完右腿一抬，$N顺势应了一招青城派的「屁股向后，平沙落雁式」"
            "－－叭叽\n\n", ob);
        remove_call_out("kicking");
        call_out("kicking",1,ob);

}

void kicking(object ob)
{
        if (!ob || environment(ob) != environment())
                return;

        ob->move("/d/city/pomiao");
         message("vision","只听“嘭”地一声，紧接着" +  ob->query("name") +
                "从小门里飞了出来，屁股上有一个清楚的鞋印。\n", environment(ob), ob);
}

void attempt_apprentice(object ob)
{
        command("say 老夫不收徒弟，" + RANK_D->query_respect(ob) + "还是请回吧。");
}

int ask_me_1()
{
	object obj;
	object ob=this_player();
	int n=ob->query("dai");
	if ((string)ob->query("family/family_name")!="丐帮")
	{
		command("say "+ RANK_D->query_respect(ob) +"非我帮中人，如何可拿青竹令。");
		return 1;
	}
	if (ob->query("combat_exp")<(2000+500*(n-1))*n*n)
	{
		command("say "+ RANK_D->query_respect(ob) +"经验不够，不能拿青竹令。");
		return 1;
	}
	command("say 好吧，凭此令你可以和你的大师兄切磋武艺。");
        obj = new("d/gaibang/obj/qingzhu-ling1");
        obj->move(this_player());
	return 1;
}

int ask_me_2()
{
        object obj;
        object ob=this_player();
        if ((string)ob->query("family/family_name")!="丐帮")
        {
                command("say "+ RANK_D->query_respect(ob) +"非我帮中人，此话从何说起。");
                return 1;
        }
	command("say 给我"+ RANK_D->query_respect(ob) +"和你大师兄比武获胜所得的青竹令就可以升袋。");
	return 1;
}

int accept_object(object ob, object obj)
{
        object me = this_object();

        mapping my_fam  = me->query("family");
        mapping ob_fam  = ob->query("family");
	object obje;


        if((obj->query("id") == "qingzhu ling")
	&& ((string)ob->query("family/family_name")== "丐帮")
	&& ob->query_temp("have_win"))
        {	
		command("say 既然"+ RANK_D->query_respect(ob) +"战胜了大师兄，那就可以升袋了。");
	ob->delete_temp("have_win");
	ob->set("combat_exp", ob->query("combat_exp") + 1500 * ob->query("dai") * ob->query("dai"));
                ob->set("dai", ob->query("dai")+1);
                obje=new("/d/gaibang/obj/gaibang-bag");
                obje->move(ob);
                remove_call_out("destroying");
                call_out("destroying", 1, me, obj);
		return 1;	
	}
        command("smile");
        command("say 这东西给我可没有什麽用。");
        command("give " + obj->query("id") + " to " + me->query("id"));
        return 0;

}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

