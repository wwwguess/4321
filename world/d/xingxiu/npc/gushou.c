// gushou.c ����

#include <ansi.h>

inherit NPC;

void create()
{
         set_name(MAG "������" NOR + YEL "����" NOR, ({ "gu shou", "gushou" }));
        set("long", 
                "���������ɵĴ����֡�\n"
                "����ǰ����һֻͭ�ģ�һ����һ�߳���ɤ�ӳ�Щ����Ļ���\n");
        set("gender", "����");
        set("age", 43);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 26);
        set("int", 16);
        set("con", 20);
        set("dex", 20);

        set("max_kee", 400);
        set("max_gin", 400);
        set("force", 400);
        set("max_force", 400);
        set("force_factor", 10);
        set("combat_exp", 4000);

        set_skill("force", 40);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_skill("parry", 40);

//      create_family("������", 3, "������");

        setup();
        set("chat_chance", 2);
        set("chat_msg", ({
"��������ͭ�ģ��������������ǡ��ޡ��ϡ��ɣ�������御����\n",
"��������ͭ�ģ��������������ǡ��ޡ��ϡ��ɣ��¡��䡫�졫�ء���\n",
"��������ͭ�ģ��������������ǡ��ޡ��ϡ��ɣ��š����ޡ��ȡ���\n",
        }) );

        carry_object("/d/xingxiu/obj/tonggu")->wield();
}

