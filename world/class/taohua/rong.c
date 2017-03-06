// huang-rong.c -����

#include <ansi.h>

inherit NPC;

int ask_ji();

void create()
{
        set_name("����", ({ "huang rong", "huang", "rong" }));
        set("long",
	"�����ļ������������˿�����Ϊ����һ�㡣\n"
	"���ǵ�����������ķ��ˣ��͹�����һ���������������ж��ꡣ\n"
	"����������ؤ��������书��ȻҲ���˵á�\n");

	set("nickname", GRN "�����" NOR);
	set("title", YEL "������" NOR);
        set("gender", "Ů��");
        set("age", 36);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 30);
        set("con", 28);
        set("kar", 28);
	set("per", 36);

        set("max_kee", 800);
        set("max_gin", 600);
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 20);
	set("combat_exp", 1000000);
        set("score", 5000);
        set("chat_chance",10);  
            
        set("chat_msg", ({
            "����˵��:���ɹŴ��ɸ��Ҫ˧�ر��������������ˡ���\n"
           }));
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "staff.chan" :)
        }) );

	set_skill("literate", 200);
	set_skill("qimen-bagua", 200);
        set_skill("force", 80);
	set_skill("taohua-force", 80);
        set_skill("dodge", 110);
        set_skill("parry", 90);
        set_skill("sword", 80);
        set_skill("yuxiao-jian", 80);
	set_skill("staff", 120);
	set_skill("dagou-bang", 150);
        set_skill("baguabu", 90);
        set_skill("hand", 90);
        set_skill("lanhua-shou", 100);
        set_skill("strike", 80);
        set_skill("luoying-zhang", 100);

	map_skill("force", "taohua-force");
        map_skill("parry", "lanhua-shou");
        map_skill("sword", "yuxiao-jian");
        map_skill("dodge", "baguabu");
        map_skill("strike", "luoying-zhang");
        map_skill("hand", "lanhua-shou");
	map_skill("staff", "dagou-bang");

        prepare_skill("strike", "luoying-zhang");
 	prepare_skill("hand", "lanhua-shou");

        create_family("�һ���", 2, "����");

        set("inquiry", ([
                "�л���" : (: ask_ji :),
        ]));

        setup();
	
//	carry_object("/kungfu/class/gaibang/zhuzhang");

}

int ask_ji()
{
	command("say �л������ǻ������������������سǣ�"+ RANK_D->query_respect(this_player())+ "������һ�󹦣��ҾͿ��Ը���������");
	this_player()->set_temp("ask-ji", 1);
	return 1;
}

int accept_object(object ob, object obj)
{
	object obj1,obj2;
	object me=this_object();   
        if (obj->query("id")=="jun ling") 
          {                            
            if (!ob->query_temp("havesword"))
            {command("say �벻����λӢ��������£��������֮��ȥ�Ͻ��׼�!");
            command("say �����Իر����Ͱ���Ѹ����õ����콣����Ӣ�ۡ�");
            obj2=new("/d/taohua/obj/skysword"); 
            obj2->move(ob);               
            ob->set_temp("havesword",1);
	    write("���ݸ���һ�����콣��\n");   
            remove_call_out("destroying");
            call_out("destroying", 1, ob, obj);
            return 1;
            }
            else
            {command("say ���Ѿ�û�п��Ը���λӢ�۵��ˡ�");
             } 
            return 1;
           }
        if (obj->query("id")!="rentou" || obj->query("name")!="�ɹ�ǧ�򳤵���ͷ")
	{
		command("say �ⶫ�����ҿ�ûʲô�á�");
		return 0;
	}

	if (ob->query_temp("ask-ji"))
	{
		command("say ��Ȼ" + RANK_D->query_respect(ob) + "ɱ���ɹ���ʿ�����Ҿ͸��������ɣ�");
                obj1=new("/kungfu/class/gaibang/jiaohuaji");
                obj1->move(ob);
		write("���ظ���һֻ�л�����\n");
		ob->delete_temp("ask-ji");
	}
	else
	{
		command("say �벻��" + RANK_D->query_respect(ob) + "Ҳ����������嵨��\n");
		ob->set("shen", ob->query("shen") + 100);
	}

	remove_call_out("destroying");
	call_out("destroying", 1, me, obj);
        return 1;
}


void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

int accept_fight(object ob)
{
	command("say �ðɣ������ǵ㵽Ϊֹ��");
	command("wield zhuzhang");
	return 1;
}

