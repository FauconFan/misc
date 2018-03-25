package src.ast_rep;

import java.awt.Graphics2D;

public abstract class BlockAST
{
	private int x;
	private int y;
	private String name;
	private BlockASTLeaf[] childs;

	public BlockAST(int x, int y, String name, BlockASTLeaf[] childs)
	{
		this.x = x;
		this.y = y;
		this.name = name;
		this.childs = childs;
	}

	public int getX()
	{
		return (this.x);
	}

	public int getY()
	{
		return (this.y);
	}

	public void setX(int x)
	{
		this.x = x;
	}

	public void setY(int y)
	{
		this.y = y;
	}

	public void setParentRecu()
	{
		for (BlockASTLeaf bal : this.childs)
		{
			bal.setParent(this);
			bal.setParentRecu();
		}
	}

	public void setCoordsRecu(Graphics2D g2d)
	{
		int size_tot = 0;
		int ecart = 20;
		int actu = 0;

		for (BlockASTLeaf bal : this.childs)
		{
			size_tot += CalculationPoint.boxWidth(bal.getName(), g2d);
		}
		size_tot += (this.childs.length >= 1) ? (this.childs.length - 1) * ecart : 0;

		for (BlockASTLeaf bal : this.childs)
		{
			int size_actu = CalculationPoint.boxWidth(bal.getName(), g2d);

			bal.setX(this.getX() + actu - size_tot / 2 + size_actu / 2);
			bal.setY(this.getY() + 100);
			actu += size_actu;
			actu += ecart;
		}
		for (BlockASTLeaf bal : this.childs)
		{
			bal.setCoordsRecu(g2d);
		}
	}

	public void paintBlockRecu(CanvasAST cast, Graphics2D g2d, CalculationPoint parent)
	{
		CalculationPoint cp = new CalculationPoint(cast, g2d, this);
		g2d.drawString(cp.name, cp.x, cp.y);
		g2d.drawRect(cp.boxX, cp.boxY, cp.boxWidth, cp.boxHeight);

		if (parent != null)
		{
			g2d.drawLine(
				parent.getX() + parent.getWidth() / 2,
				parent.getY() + (int)(CalculationPoint.deltaY * cast.getZoom()),
				cp.getX() + cp.getWidth() / 2,
				cp.getY() - cp.getHeight());
		}
		for (BlockASTLeaf bast : this.childs)
		{
			bast.paintBlockRecu(cast, g2d, cp);
		}
	}

	public String getName()
	{
		return (this.name);
	}
}